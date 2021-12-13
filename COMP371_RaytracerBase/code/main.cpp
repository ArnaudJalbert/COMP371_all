

using namespace std;

#include <iostream>
#include <string>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

#include "external/json.hpp"
#include "external/simpleppm.h"

#ifdef COURSE_SOLUTION
#include "src/RayTracer.h"
#endif


int test_eigen();
int test_save_ppm();
int test_json(nlohmann::json& j);
    
int main(int argc, char* argv[])
{
    if(argc!=2){
        cout<<"Invalid number of arguments"<<endl;
        cout<<"Usage: ./raytracer [scene] "<<endl;
        cout<<"Run sanity checks"<<endl;
        
        test_eigen();
        test_save_ppm();
        
        
    } else {
        
        cout<<"Scene: "<<argv[1]<<endl;
        
        std::ifstream t(argv[1]);
        if(!t){
            cout<<"File "<<argv[1]<<" does not exist!"<<endl;
            return -1;
        }
        
        std::stringstream buffer;
        buffer << t.rdbuf();
        
        nlohmann::json j = nlohmann::json::parse(buffer.str());
        cout<<"Parsed successfuly"<<endl;
        
#ifdef COURSE_SOLUTION
        RT371::RayTracer<RT371::Kernelf> rt(j);
        cout<<"Running!"<<endl;
        rt.run();
#else
        
        test_eigen();
        test_save_ppm();
        
        if(test_json(j)==0){
            
        } else {
            cout<<"Could not load file!"<<endl;
        }
#endif
    }
  
    
    
    return 0;
}
