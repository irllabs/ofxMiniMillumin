#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxHomography.h"
#include "ofxDatGui.h"

#define PUPPET_STAGE_SYPHON_NAME "Dranimate_Syphon_1"
#define PUPPET_PARADE_PATH_SYPHON_NAME "Dranimate_PuppetParadePath"

#define DEFAULT_WINDOW_WIDTH 1024
#define DEFAULT_WINDOW_HEIGHT 768

#define INITIAL_DISPLAY_OFFSET_X 0
#define INITIAL_DISPLAY_OFFSET_Y 0

#define VERTEX_SELECT_THRESHOLD 50

#define SELECTED_VERTEX_CIRCLE_SIZE 10

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg);
    void serverRetired(ofxSyphonServerDirectoryEventArgs &arg);
    
    void drawGrid(int xPos, int yPos, int xDivs, int yDivs, int w, int h);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void moveHomCornerPos(int i, int dx, int dy);
    void setHomCornerPos(int i, int x, int y);

    ofxSyphonClient puppetStageClient;
    ofxSyphonClient puppetParadePathClient;
    
    ofImage test;
    
    bool drawTestImage = true;
    bool drawPuppetParadePath;
    bool drawGui = true;
    
    int hoveredOverVertexIndex;
    
    ofPoint originalCorners[4];
    ofPoint distortedCorners[4];
    ofMatrix4x4 homography;
    
    ofxDatGui *gui;
    
    ofxSyphonServerDirectory dir;
    
    bool shiftKeyDown;
    bool oneKeyDown;
    bool twoKeyDown;
    bool threeKeyDown;
    bool fourKeyDown;
    bool upKeyDown;
    bool rightKeyDown;
    bool downKeyDown;
    bool leftKeyDown;
    
    ofTrueTypeFont myfont;
    
};
