#include "ObjectCollisionDetector.h"
#include "TriangleIntersectionDetector.h"

namespace Nade{
  std::vector<glm::vec3> ObjectCollisionDetector::DeriveTriangles(GameObject& object){
    std::vector<glm::vec3> triangle;
    for(int i = 0; i < object.GetData().model.data.Vsize; i=i+3){
      std::vector<float> pos = object.GetData().model.data.mPosition;
      triangle.push_back(glm::vec3(pos.at(i), pos.at(i+1), pos.at(i+2)));           //For every 3 vertex position floats, construct a vec3 and push into flat triangle list
    }
    return triangle;
  }
  void ObjectCollisionDetector::Detect(GameObject& object1, GameObject& object2){
    std::vector<glm::vec3> triangle1 = DeriveTriangles(object1);
    std::vector<glm::vec3> triangle2 = DeriveTriangles(object2);
    
    std::vector<glm::vec3> T1;
    std::vector<glm::vec3> T2;

    for(int i = 0; i < triangle1.size()/3; i=i+3){                                  //Extract each triangle out of flat triangle list
      T1.push_back(triangle1.at(i) + object1.GetPosition());
      T1.push_back(triangle1.at(i+1) + object1.GetPosition());
      T1.push_back(triangle1.at(i+2) + object1.GetPosition());
      
      for(int i = 0; i < triangle1.size()/3; i=i+3){                                //Iterate over every triangle in the other flat triangle list 
        T2.push_back(triangle2.at(i) + object2.GetPosition());
        T2.push_back(triangle2.at(i+1) + object2.GetPosition());
        T2.push_back(triangle2.at(i+2) + object2.GetPosition());

        TraingleIntersectionDetector::Detect(T1, T2);                               //And check intersection among both
      } 
    }
  }
}