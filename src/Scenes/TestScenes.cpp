///*
// * TestScenes.cpp
// *
// *  Created on: May 12, 2011
// *      Author: raphael
// */
//
//#include "TestScenes.h"
//
//// returns 1 - 6 for blur texture units
//// curPixBuf is always between 0 and 5
//
//int curBlurTarget = 0;
//void AdvanceBlurTaget() { curBlurTarget = ((curBlurTarget+ 1) %6); }
//GLuint GetBlurTarget0(){ return (1 + ((curBlurTarget + 5) %6)); }
//GLuint GetBlurTarget1(){ return (1 + ((curBlurTarget + 4) %6)); }
//GLuint GetBlurTarget2(){ return (1 + ((curBlurTarget + 3) %6)); }
//GLuint GetBlurTarget3(){ return (1 + ((curBlurTarget + 2) %6)); }
//GLuint GetBlurTarget4(){ return (1 + ((curBlurTarget + 1) %6)); }
//GLuint GetBlurTarget5(){ return (1 + ((curBlurTarget) %6)); }
//
//
//void SetupBlurProg(void)
//{
//	// Set the blur program as the current one
////	glUseProgram(blurProg);
//
//	// Set MVP matrix
//	//glUniformMatrix4fv(glGetUniformLocation(blurProg, "mvpMatrix"), 1, GL_FALSE, transformPipeline.GetModelViewProjectionMatrix());
//
//	// Setup the textue units for the blur targets, these rotate every frame
//	glUniform1i(glGetUniformLocation(postShader->id, "textureUnit0"), GetBlurTarget0());
//	glUniform1i(glGetUniformLocation(postShader->id, "textureUnit1"), GetBlurTarget1());
//	glUniform1i(glGetUniformLocation(postShader->id, "textureUnit2"), GetBlurTarget2());
//	glUniform1i(glGetUniformLocation(postShader->id, "textureUnit3"), GetBlurTarget3());
//	glUniform1i(glGetUniformLocation(postShader->id, "textureUnit4"), GetBlurTarget4());
//	glUniform1i(glGetUniformLocation(postShader->id, "textureUnit5"), GetBlurTarget5());
//}
//int shininess = 8;
//float r,g,b = 0.5;
//int render2()
//{
//
//
//	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//
//    angleX += 0.001;
//    angleY += 0.001;
//    angleZ += 0.001;
//
//    shader->bind();
//
//    glm::mat4 Modelview = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, 0.0f));//    NormalMatrix = Modelview.getUpper3x3();
//    Modelview = glm::rotate(Modelview,glm::degrees(angleX),glm::vec3(1.0,0.0,0.0));
//    Modelview = glm::scale(Modelview,glm::vec3(20,20,20));
//    Modelview = camera->getCameraMatrix() * Modelview; //*Modelview
//    glm::mat3 normMatrix = glm::mat3(Modelview);
//
//	std::vector<unsigned char> message;
//	int nBytes, i;
//	double stamp;
//
//	stamp = midiin->getMessage( &message );
//	nBytes = message.size();
//	for ( i=0; i<nBytes; i++ )
//	  std::cout << "Byte " << i << " = " << (int)message[i] << ", ";
//	if ( nBytes > 0 )
//	  std::cout << "stamp = " << stamp << std::endl;
//
//	if (nBytes){
//		switch ((int)message[1])
//			case 7: {
//				shininess = (int)message[2];
//				break;
//			case 91:
//				r = (float)message[2]/127.0;
//				break;
//
//			case 93:
//				g = (float)message[2]/127.0;
//				break;
//
//			case 74:
//				b = (float)message[2]/127.0;
//				break;
//		}
//	}
//    shader->bind();
//    glUniformMatrix4fv( shader->getUniformLocation("Projection"), 1,0, &P[0][0]);
//    glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
//    glUniformMatrix3fv(shader->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
//
//    glUniform3f(shader->getUniformLocation("LightPosition"),0,0,5);
//    glUniform3f(shader->getUniformLocation("AmbientMaterial"), 0.04f, 0.04f, 0.04f);
//    glUniform3f(shader->getUniformLocation("DiffuseMaterial"), r, g, b);
//    glUniform3f(shader->getUniformLocation("SpecularMaterial"), 1.0,1.0,1.0 );
////    glUniform1f(shader->getUniformLocation("Shininess"), glfwGetTime());
//    glUniform1f(shader->getUniformLocation("Shininess"), shininess);//
//
//    glUniform1f(shader->getUniformLocation("Time"),glfwGetTime());
//
//    //fbo->attach();
//    ctm->draw();
//    shader->unbind();
//
//    // First bind the PBO as the pack buffer, then read the pixels directly to the PBO
//    		glBindBuffer(GL_PIXEL_PACK_BUFFER, pboID);
//    		glReadPixels(0, 0, engine->getWidth(), engine->getHeight(), GL_RGB, GL_UNSIGNED_BYTE, NULL);
//    		glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
//
//    		// Next bind the PBO as the unpack buffer, then push the pixels straight into the texture
//    		glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID);
//
//            // Setup texture unit for new blur, this gets imcremented every frame
//    		glActiveTexture(GL_TEXTURE0+GetBlurTarget0() );
//    		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, engine->getWidth(), engine->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
//    		glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
//    		//glDrawBuffer()
//
//
//    //printf("%d \n",message[0]);
//
//	//printf("%d %d\n",textureId,texture->getTextureID());
//	//texture->bindTexture();
//
//
//    		//post processing
////    postShader->bind();
////    glm::mat4 noTrans = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, -1.0f));
////    glUniformMatrix4fv( textureShader->getUniformLocation("Projection"), 1,0, &P[0][0]);
////    glUniformMatrix4fv(textureShader->getUniformLocation("Modelview"), 1, 0,&noTrans[0][0]);
////    glUniformMatrix3fv(textureShader->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
////    SetupBlurProg();
////    screenRect->draw();
////    postShader->unbind();
////    AdvanceBlurTaget();
//    return 1;
//}
//
//int renderlossless()
//{
//	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//
//    angleX += 0.001;
//    angleY += 0.001;
//    angleZ += 0.001;
//
//    shader->bind();
//
//    glm::mat4 Modelview = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, -0.0f));//    NormalMatrix = Modelview.getUpper3x3();
//    //Modelview = glm::rotate(Modelview,glm::degrees(angleX),glm::vec3(1.0,0.0,0.0));
//    Modelview = glm::scale(Modelview,glm::vec3(10,10,10));
//    Modelview = camera->getCameraMatrix() * Modelview; //*Modelview
//    glm::mat3 normMatrix = glm::mat3(Modelview);
//
//    glUniformMatrix4fv( shader->getUniformLocation("Projection"), 1,0, &P[0][0]);
//    glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
//    glUniformMatrix3fv(shader->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
//
//    glUniform3f(shader->getUniformLocation("LightPosition"),0,0,5);
//    glUniform3f(shader->getUniformLocation("AmbientMaterial"), 0.04f, 0.04f, 0.04f);
//    glUniform3f(shader->getUniformLocation("DiffuseMaterial"), 0.0f, 1.0f, 1.0f);
//    glUniform3f(shader->getUniformLocation("SpecularMaterial"), 1.0,1.0,1.0 );
////    glUniform1f(shader->getUniformLocation("Shininess"), glfwGetTime());
//    glUniform1f(shader->getUniformLocation("Shininess"), track->getPeak()*glfwGetTime());
//
//    glUniform1f(shader->getUniformLocation("Time"),glfwGetTime());
//
//    ctm->draw();
//    shader->unbind();
//
//    return 1;
//}
//
//int renderQuad()
//{
//	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//
//    angleX += 0.001;
//    angleY += 0.001;
//    angleZ += 0.001;
//
//    shader->bind();
//
//    glm::mat4 Modelview = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, 0.0f));//    NormalMatrix = Modelview.getUpper3x3();
//    Modelview = glm::rotate(Modelview,glm::degrees(angleX),glm::vec3(1.0,0.0,0.0));
//    Modelview = glm::scale(Modelview,glm::vec3(20,20,20));
//    Modelview = camera->getCameraMatrix() * Modelview; //*Modelview
//    glm::mat3 normMatrix = glm::mat3(Modelview);
//
//    glm::mat4 noTrans = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, -100.0f));
//    glUniformMatrix4fv( textureShader->getUniformLocation("Projection"), 1,0, &P[0][0]);
//    glUniformMatrix4fv(textureShader->getUniformLocation("Modelview"), 1, 0,&noTrans[0][0]);
//    glUniformMatrix3fv(textureShader->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
//    screenRect->draw();
//    shader->unbind();
//
//    return 1;
//}







//int render()
//{
//	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//
//    angleX += 0.001;
//    angleY += 0.1;
//    angleZ += 0.1;
//
//    shader->bind();
//    //shader->setUniformValue("time",glfwGetTime());
//
//    //Matrix4 rotation = Matrix4::rotationY(rc.Theta * Pi / 180.0f);
//    glm::mat4 Modelview = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, -10.0f));//    NormalMatrix = Modelview.getUpper3x3();
////    Modelview = glm::rotate(Modelview,glm::degrees(angleX),glm::vec3(1.0,1.0,0.0));
//    Modelview = glm::scale(Modelview,glm::vec3(1,1,1));
//    Modelview = camera->getCameraMatrix(); //*Modelview
//    glm::mat3 normMatrix = glm::mat3(Modelview);
//
//
//
//
//
//    glUniformMatrix4fv( shader->getUniformLocation("Projection"), 1,0, &P[0][0]);
//    glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
//    glUniformMatrix3fv(shader->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
//
//    glUniform3f(shader->getUniformLocation("LightPosition"),0,0,1);
//    glUniform3f(shader->getUniformLocation("AmbientMaterial"), 0.04f, 0.04f, 0.04f);
//    glUniform3f(shader->getUniformLocation("DiffuseMaterial"), 0.0, 1.0, 0.1);
//    glUniform1f(shader->getUniformLocation("SpecularMaterial"), 240);
//    glUniform3f(shader->getUniformLocation("Shininess"), 1.0, 1, 1);
//    glUniform1f(shader->getUniformLocation("Time"),glfwGetTime());
//    //glUniform1f(SH_TIME,glfwGetTime());
//    //shader->setUniformValue("Time",glfwGetTime());
//
//    //glUniform3f(shader->getUniformLocation("DiffuseMaterial"), sin(glfwGetTime()/10.0), sin(glfwGetTime()), sin(glfwGetTime()/5.0));
//
//    //obj->draw();
//
//    ctm->draw();
//    bspline->draw();
//    bspline->drawControlPoints();
////    shader->unbind();
////
////    textureShader->bind();
////    glm::mat4 noTrans = glm::translate(glm::mat4(1.0f),glm::vec3(0.0f, 0.0f, -100.0f));
////    glUniformMatrix4fv( textureShader->getUniformLocation("Projection"), 1,0, &P[0][0]);
////    glUniformMatrix4fv(textureShader->getUniformLocation("Modelview"), 1, 0,&noTrans[0][0]);
////    glUniformMatrix3fv(textureShader->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
////    screenRect->draw();
////    textureShader->unbind();
//    //skybox->draw();
//    return 1;
//}
