#include "ofApp.h"

//--------------------------------------------------------------
// Setup all the settings and global variables
void ofApp::setup(){
    // set minimum and maximum distance of influence
    // and width, height of the Tree
    mytree = new Tree(2, 200, 700, 700);
    ofBackground(51, 51, 51);
    mytree->generateLeaves(400);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    mytree->grow();
    mytree->show();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        ofImage screenshot;
        screenshot.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        screenshot.save("screenshot.png");
    }
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
