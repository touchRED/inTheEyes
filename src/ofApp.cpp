#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetColor(0);
	ofSetCurveResolution(200);
	ofFill();

	//INITIALIZE TERRAIN ATTRIBUTES

	//choose lower-left starting point and length of terrain
	int startX = 50;
	int startY = floor(ofRandom(ofGetViewportHeight()/1.3, ofGetViewportHeight() - 100)) - 100;
	
	//dimensions of terrain
	int terrainLength = ofGetViewportWidth() - startX;
	int terrainHeight = 7;

	//controlls how close other lines are together, overall appearance of terrain
	int segmentLength = 50;
	int run = 10;
	int rise = floor(sqrt(pow(segmentLength, 2) - pow(run, 2)));

	//initialize starting point
	ofPoint startPt(startX,startY);
	line.addVertex(startPt);

	//initialize noise variable
	float noise = ofRandom(20);

	//for(int i = 1; i < floor((terrainLength - 100) / 50); i++){
	for(int i = 1; (line[i-1].x + run * terrainHeight) < terrainLength; i++){
		
		//chose angle from noise
		float rads = ofDegToRad(ofSignedNoise(noise) * 90);
		
		//create new pt at prescribed angle from previous pt
		ofPoint pt(line[i-1].x + (cos(rads) * segmentLength), line[i-1].y + (sin(rads) * segmentLength));
		
		//add pt to line
		line.addVertex(pt);
		
		//travel through noise
		noise += 0.3;
	}

	//initialize lines with starting line
	lines.push_back(line);

	//create more lines by translating the first line
	for(int i = 1; i < terrainHeight; i++){
		ofPolyline newLine;
		
		//translate each point according to rise and run
		for(auto pt : line.getVertices()){
			ofPoint newPt;
			newPt.set(pt.x + (run * i), pt.y - (rise * i));
			newLine.addVertex(newPt);
		}
		lines.push_back(newLine);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//verbal cues
	ofDrawBitmapStringHighlight("LOOK THEM", 100, 200);
	ofDrawBitmapStringHighlight("IN THE EYES", ofGetViewportWidth() - 170, 550);

	//draw lines
	for(auto &l : lines){
		l.draw();
	}

	//draw connecting seams across lines
	for(int i = 0; i < line.size(); i++){
		
		//draw a line from the bottom to the top
		ofDrawLine(line[i].x, line[i].y, lines[lines.size() - 1][i].x, lines[lines.size() - 1][i].y);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
