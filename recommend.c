#include <stdio.h>
#include <math.h>

static const double energyPercentage = 45.0;
static const double carboPercentage = 7.55;
static const double proteinPercentage = 1.45;
static const double pipidPercentage = 1;

static const double INF = 987654321.0;
typedef struct nutrient{

	double energy;
	double carbo;
	double protein;
	double pipid;

}nutrient;

double getVariance(nutrient unit);

int main(){


	//DB Input
	
	nutrient totalAmount;
	totalAmount.energy = 111.0;
	totalAmount.carbo = 21.0;
	totalAmount.protein = 32.0;
	totalAmount.pipid = 14.0;

	//This all value is just Example. We should delete them..
	//Each unit will be kcal, g, g, g
	
	double foodAmount = 2.0; 		//Example. This means, person eats 2 Plates
	nutrient unit; 				//The optimal food will make this unit's element to 1 approximately
	

	double minForIndex = INF;
	int index;

	while(1){ 			//Find Suitable Food in DB
		nutrient currentFood;
		 		//This Index& currentIndex  also Example. In real, it should be removed
		int currentIndex; 	

		//Read currentFood's elements

		unit.energy = (totalAmount.energy + currentFood.energy*foodAmount)/energyPercentage;
		unit.carbo = (totalAmount.carbo + currentFood.carbo*foodAmount)/carboPercentage;
		unit.protein = (totalAmount.protein + currentFood.protein*foodAmount)/proteinPercentage;
		unit.pipid = (totalAmount.pipid + currentFood.pipid*foodAmount)/pipidPercentage;


		double currentVariance = getVariance(unit);
		//This is Wrong. Not Minimum. Just absolute 1

		double currentDifference = abs(currentVariance - 1);

		if(minForIndex > currentDifference){
			minForIndex = currentVariance;
			index = currentIndex;

		}
	}

	//Now 
	//Only Pseudo Code.
	//Just Index will indicate the Optimal foods
	printf("%d", index);
	//This index Value will be answer


	return 0;
}


double getVariance(nutrient unit){
	double sum = 0, average, varSum = 0;
	double standardDeviation, variance;

	sum = unit.energy+ unit.carbo + unit.protein + unit.pipid;
	average = sum/4;


	varSum += pow((unit.energy - average), 2);
	varSum += pow((unit.carbo - average), 2);
	varSum += pow((unit.protein - average), 2);
	varSum += pow((unit.pipid - average), 2);

	standardDeviation = varSum/3; 			//Divide n-1
	variance = sqrt(standardDeviation);

	return variance;
}


