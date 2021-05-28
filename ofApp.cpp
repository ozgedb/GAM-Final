
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(227,228,224);
    ofSetCylinderResolution(128,64);
    ofSetSphereResolution(128);
    
    gui.setup();
    gui.add(uiAmount.set("amount",1,1,11));
    gui.add(uiPower.set("power",0,0,60));
    gui.add(uiLightPosition.set("light position",
                                ofVec3f(0),
                                ofVec3f(-300),
                                ofVec3f(300)));

    

                        
    //second part
    cam.setDistance(100);
    
    
    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            mesh.addVertex(ofPoint(x - size/ 2, y - size / 2));
         }
        }
    for (int x = 0; x < size - 1; x++){
        for (int y = 0; y < size - 1; y++) {
            
            mesh.addIndex(x + y * size);
            
            
           
                    
                    
                    
                    
                   
                    
                }
            }
        }
           
            
            
        
    


//--------------------------------------------------------------
void ofApp::update(){
    //light.setPosition(uiLightPosition->x, uiLightPosition->y, uiLightPosition->z);
    int count = 0;
    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++) {
            ofVec3f position = mesh.getVertex(count);
            position.z = ofMap(ofNoise(count, ofGetElapsedTimef()), 0, 1, 0, uiAmount);
            mesh.setVertex(count,position);
            count++;
            
            
                        
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofEnableDepthTest();
    //light.enable();
    cam.begin();
    ofSetColor(229,188,130);
    mesh.drawWireframe(); //mesh.draw();
    
    
    
    for(int i=0; i< uiAmount; i++){
        for (int j= 0; j < uiAmount; j++) {
            float y = sin(ofGetElapsedTimef() + i) * uiPower;
            //ball color
            ofSetColor(0,200);
            ofDrawSphere(i * 64,48 - y, j * 64,16);
            //red
            ofSetColor(233,65,42);
            ofDrawCylinder(i * 1, 0, j * 1, 1, 1);
            //yellow
            ofSetColor(254,214,93);
            ofDrawSphere(180,70,20,80);
           
            
            //red
            ofSetColor(233, 64, 33);
            ofDrawSphere(ofGetWidth()/2, ofGetHeight()/2,100);
            
            //brown
            ofSetColor(60, 51, 35);
            ofDrawSphere(ofGetWidth()/15, ofGetHeight()/42,40);
            
            //white
            ofSetColor(247,247,246);
            ofDrawSphere(200,300,50,100);
        
            //ofSetColor(255,220,149);
            ofDrawLine(600,600,600,600);
           
            
            ofSetColor(244,244,223);
                       ofDrawSphere(1,100,300,60);
            
            
        }
    }
    
    
    
    
    
    cam.end();
    //light.disable();
    ofDisableDepthTest();
    ofPopMatrix();
    if(bHide){
        gui.draw();
        
        //third part
        
        
       
        
        
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    bHide =!bHide;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
