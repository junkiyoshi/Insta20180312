#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetColor(39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofSeedRandom(39);

	float size = 30;
	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += size * 1.1) {

		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += size * 1.1) {

			float noise_value = ofNoise(x * 0.002, y * 0.002, ofGetFrameNum() * 0.005);
			noise_value = noise_value > 0.65 ? noise_value - 0.65 : 0;
			float h = size + noise_value * size * 50;

			ofColor body_color;
			body_color.setHsb(ofRandom(255), 239, 239);

			ofFill();
			ofSetColor(body_color, 139);
			ofDrawBox(ofPoint(x, y, h / 2), size, size, h);

			ofNoFill();
			ofSetColor(body_color);
			ofDrawBox(ofPoint(x, y, h / 2), size, size, h);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}