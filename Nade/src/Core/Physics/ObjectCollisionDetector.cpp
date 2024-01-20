#include "ObjectCollisionDetector.h"

void Nade::ObjectCollisionDetector::Detect(GameObject& object, GameObject& object2){
    std::vector<glm::vec3> triangle1;
    Nade::TraingleIntersectionDetector::DeriveTriangles(object, triangle1);
    std::vector<glm::vec3> triangle2;
    Nade::TraingleIntersectionDetector::DeriveTriangles(object2, triangle2);

    for(int i = 0; i < triangle1.size(); i++){
      triangle1.at(i) += object.GetPosition();
    }
    for(int i = 0; i < triangle2.size(); i++){
      triangle2.at(i) += object2.GetPosition();
    }

    for(int i = 0; i < triangle1.size()/3; i++){
      std::vector<glm::vec3> t1;
      std::vector<glm::vec3> t2;
      t1.push_back(triangle1.at(i));
      t1.push_back(triangle1.at(i+1));
      t1.push_back(triangle1.at(i+2));
      for(int j = 0; j < triangle2.size()/3; j++){
        t2.push_back(triangle2.at(j));
        t2.push_back(triangle2.at(j+1));
        t2.push_back(triangle2.at(j+2));
        int col = Nade::TraingleIntersectionDetector::Detect(triangle1, triangle2);
        if(col){
          Nade::PhysicsObject::SetPhysicsObject(object, false);
          object.velocity = 0;
          Nade::PhysicsObject::SetPhysicsObject(object2, false);
          object2.velocity = 0;
        }
      }
    }
}