#include "ObjectCollisionDetector.h"

void Nade::ObjectCollisionDetector::Detect(GameObject& object, GameObject& object2){
    std::vector<glm::vec3> triangle1;
    Nade::TraingleIntersectionDetector::DeriveTriangles(object, triangle1);
    std::vector<glm::vec3> triangle2;
    Nade::TraingleIntersectionDetector::DeriveTriangles(object2, triangle2);

    for(int i = 0; i < 3; i++){
      triangle1.at(i) += object.GetPosition();
    }
    for(int i = 0; i < 3; i++){
      triangle2.at(i) += object2.GetPosition();
    }

    Nade::TraingleIntersectionDetector::Detect(triangle1, triangle2);
}