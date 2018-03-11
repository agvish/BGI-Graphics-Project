#include <iostream>
#include <windows.h>
#include <string>
#include "graphics.h"
#include "primitives.h"
#include "physics.h"
#include "matrix.h"
#include "assets.h"

int main()
{

    const double acceleration = 0.0, stepSize = 0.5; // arbitrary acceleration value - for g take 9.8
	double theta = 0.0;


	primitives :: Point locus, nextPoint,arrowHead,arrowTail;
	primitives :: Circle ball;
	primitives :: AABB ballBB, prevBB, upRodBB, downRodBB;//prevupRodBB,prevdownRodBB;
	primitives :: Rectangle upRod,downRod;
	//std::cout << "Please enter the coordinates for the next point along the path of the ball (x,y)." << std::endl;
	//std::cin >> nextPoint.x >> nextPoint.y; // the closer this point is to the center of the ball, the lower the velocity and vice versa

	initwindow(800, 480, "First Sample");
	setcolor(12); // Light Red

	int xMax = getmaxx(), yMax = getmaxy();
	ball.center.x=100;ball.center.y=yMax-30;ball.radius=30;//BALL POSITIONING AND RADIUS
	arrowTail.x=ball.center.x;arrowTail.y=ball.center.y;arrowHead.x=arrowTail.x+70;arrowHead.y=arrowTail.y;//ARROW POSITIONING
	upRod.tL.x = 400;upRod.tL.y = 0;upRod.bR.y = 150;upRod.bR.x = upRod.tL.x+30;//UPPER ROD POSITIONING
    downRod.tL.x = upRod.tL.x;downRod.bR.x = upRod.bR.x;downRod.bR.y = getmaxy();downRod.tL.y = upRod.bR.y+100;//LOWER ROD POSITIONING
    upRod.width=30;downRod.width=30;upRod.height = upRod.bR.y-upRod.tL.y;downRod.height=downRod.bR.y-downRod.tL.y;//WIDTH AND HEIGHT OF RODS
    upRod.center = midPoint(upRod.bR,upRod.tL);downRod.center = midPoint(downRod.bR,upRod.tL);//MIDPOINT OF RODS
   // prevupRodBB=upRodBB; prevdownRodBB=downRodBB;
	primitives :: genFootball(ball.center,ball.radius);
	primitives :: drawRods(upRod,downRod);
	primitives :: genGoalPost();
	primitives :: drawArrowFootball(arrowHead,arrowTail);
	//primitives :: arrowMovement(arrowHead,arrowTail);
    //primitives :: drawArrowFootball(arrowHead,arrowTail);
	//ballBB = updateAABB(ball.center, 2 * ball.radius, 2 * ball.radius); // binds the axis aligned bounding box to the ball for the first time
	//upRodBB = updateAABB(upRod.mid,upRod.width,upRod.height);
	//downRodBB = updateAABB(downRod.mid,downRod.width,downRod.height);
	/*while (1) // check this
	{
		//line(l.src.x, l.src.y, l.dst.x, l.dst.y); for testing collisions
		cleardevice();
		locus = getNextPositionVerlet(ball.center, nextPoint, acceleration, stepSize, theta); // locus is the next position of the center of the ball along the direction of motion
		genFootball(locus, ball.radius); // primary draw call for the ball
		primitives :: drawRods(upRod,downRod);;
        primitives :: genGoalPost();


		prevBB = ballBB; // backs up the ball's bounding box
		prevupRodBB=upRodBB; prevdownRodBB=downRodBB;

		ballBB = updateAABB(locus, 2 * ball.radius, 2 * ball.radius); // updates the axis aligned bounding box for the ball with every iteration
        if (primitives :: collideCircleScreen(ball, ballBB, prevBB, stepSize, xMax, yMax, locus, nextPoint, acceleration, theta))
		{
			genFootball(locus, ball.radius);
			primitives :: drawRods(upRod,downRod);
            primitives :: genGoalPost();
		}
		if (collideCircleRectangle(ball, upRod, ballBB, prevBB, upRodBB, prevupRodBB, stepSize, xMax, yMax, locus, nextPoint, acceleration, theta))
		{
		    genFootball(locus, ball.radius);
			primitives :: drawRods(upRod,downRod);
            primitives :: genGoalPost();
		}
		if (collideCircleRectangle(ball, downRod, ballBB, prevBB, downRodBB, prevdownRodBB, stepSize, xMax, yMax, locus, nextPoint, acceleration, theta))
		{
		    genFootball(locus, ball.radius);
			primitives :: drawRods(upRod,downRod);
            primitives :: genGoalPost();
		}
				swapbuffers();
	}*/

 //   genGoalPost();
	std::cout << "X = " << xMax << " Y = " << yMax << std::endl; // for debugging


    system("pause");
    closegraph();
	return 0;
}
