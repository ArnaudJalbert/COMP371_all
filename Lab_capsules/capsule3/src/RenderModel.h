#ifndef VSPHERE_H
#define VSPHERE_H
#include <GL/glew.h>

#include "RUIObject.h"
#include <vector>

#ifdef RUNONMAC
//#include <OpenGL/gl.h>
#else

//#include <GL/gl.h>
#endif

#include "ObjModel.h"



namespace TAPP {
    
    class RenderModel :public RUIObject {
    public:
        
        RenderModel()
        :RUIObject(){
        
    }
    
        
        // Uniform variables
        
        GLuint MatrixID;
        GLuint ViewMatrixID;
        GLuint ModelMatrixID;
        GLuint LightID;
        GLuint dcID;//diffuse color
        
        
       // Geometric data buffers
        
        // vertex array
        unsigned int m_VAO;
        
        // vertex buffer
        unsigned int m_VBO;
        
        // normal buffer
        unsigned int m_NBO;
        
        // element buffer object - holds the triangle indices
        unsigned int m_EBO;
        
        void load_geometry();
        
        // shader program
        GLuint programID;
        void load_shader();
        
        ObjModel m_obj;
        
        virtual void init();
        virtual void release();
        virtual void hover(double  x, double y, int mods);
        virtual void grab(double x, double y, int b, int mods /* 0 left, 1 right, 2 middle*/);
        virtual void drag(double x, double y, int mods) ;
        virtual void resize(double x, double y);
        
        virtual void render() ;
        
        void render_general(int mode);
        
        
        virtual void render_pick_select(PickDataback& ) ; // to see if we selected this object
        virtual void render_pick_detail(PickDataback& ); // to see if we selected a certain primitive
    
};


}
#endif // TOGLAPP_H