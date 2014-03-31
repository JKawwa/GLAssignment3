/***********************************************************
     Starter code for Assignment 3

     This code was originally written by Jack Wang for
		    CSC418, SPRING 2005

		implements light_source.h

***********************************************************/

#include <cmath>
#include "light_source.h"

void AreaLight::shade( Ray3D& ray , double shadow) {
		Vector3D nvec(ray.intersection.normal);
	nvec.normalize();
	Vector3D lvec(_pos - ray.intersection.point);
	lvec.normalize();
	Vector3D vvec(-ray.dir);
	vvec.normalize();
	Vector3D rvec = (2*lvec.dot(nvec)*nvec)-lvec;
	rvec.normalize();
	double ndotl = nvec.dot(lvec), vdotr_pow_a = pow(vvec.dot(rvec),ray.intersection.mat->specular_exp);
	ray.col = ray.col + (ray.intersection.mat->ambient*_col_ambient)
		+(((ndotl>0)?ndotl:0)*ray.intersection.mat->diffuse)*_col_diffuse
		+((((vdotr_pow_a>0)?vdotr_pow_a:0)) * ray.intersection.mat->specular * _col_specular);
	
	ray.col = shadow * ray.col;
	ray.col.clamp();
}

void PointLight::shade( Ray3D& ray , double shadow) {
	// TODO: implement this function to fill in values for ray.col 
	// using phong shading.  Make sure your vectors are normalized, and
	// clamp colour values to 1.0.
	//
	// It is assumed at this point that the intersection information in ray 
	// is available.  So be sure that traverseScene() is called on the ray 
<<<<<<< HEAD:a3-2/raytracerW32/light_source.cpp
	// before this function. 

	Vector3D nvec(ray.intersection.normal);
	nvec.normalize();
	Vector3D lvec(_pos - ray.intersection.point);
	lvec.normalize();
	Vector3D vvec(-ray.dir);
	vvec.normalize();
	Vector3D rvec = (2*lvec.dot(nvec)*nvec)-lvec;
	rvec.normalize();
	double ndotl = nvec.dot(lvec), vdotr_pow_a = pow(vvec.dot(rvec),ray.intersection.mat->specular_exp);
	ray.col = ray.col + (ray.intersection.mat->ambient*_col_ambient)
		+(((ndotl>0)?ndotl:0)*ray.intersection.mat->diffuse)*_col_diffuse
		+((((vdotr_pow_a>0)?vdotr_pow_a:0)) * ray.intersection.mat->specular * _col_specular);
	
	ray.col = shadow * ray.col;
	ray.col.clamp();
}
=======
	// before this function.  

}

>>>>>>> parent of fb8f4a1... Part 1 Done:a3/raytracerW32/light_source.cpp
