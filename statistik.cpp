#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <math.h>

/**
 *  Berechnet die Anzahl der Personen aus den Häufigkeiten
 *  in der Stichprobe.
 */
double persons(std::vector<int> frequencies) 
{
  double result;
  for (int i=0; i<frequencies.size(); i++)
  { 
    result += frequencies[i];
  }
  return result;
}

/**
 * Berechnet das arithmetische Mittel.
 */
double mean(std::vector<double> values, std::vector<int> frequencies) 
{
  double result;
  for (int i=0; i<values.size(); i++)
  {
      result += values[i] * frequencies[i];
  }
  return (result / persons(frequencies));
}

/**
 * Berechnet die mittlere Abweichung.
 */
double meddeviation(std::vector<double> values, std::vector<int> frequencies)
{
    double meanvalue = mean(values, frequencies);
    double result;
    for (int i=0; i<values.size(); i++)
    {
		result += frequencies[i] * (fabs(values[i] - meanvalue));
    }
    return (result / persons(frequencies));
} 

/**
 * Berechnet die Standardabweichung.
 */
double stddeviation(std::vector<double> values, std::vector<int> frequencies)
{
    double meanvalue = mean(values, frequencies);
    double result;
    for (int i=0; i<values.size(); i++)
    {
		result += frequencies[i] * pow((values[i] - meanvalue), 2);
    }
    return sqrt(result / persons(frequencies));
} 

//
// Hauptprogramm
//

int main(int argc, char* argv[]) 
{
  using namespace std;

  if (argc < 2) 
  {
    cerr << "Aufruf: statistik <datafile>\n";
    return -1;
  }

  ifstream file(argv[1]);

  int group;
  double value;
  int frequency;

  vector<double> values;
  vector<int> frequencies;

  // Eingabedatei parsen und Werte in Vektor speichern 
  while (file >> group >> value >> frequency) 
  {
    values.push_back(value);
    frequencies.push_back(frequency);
  }

  cout << "Anzahl der Personen..: " << persons(frequencies)              << endl;
  cout << "Arithm. Mittel.......: " << mean(values, frequencies)         << endl;
  cout << "Mittl. Abweichung....: " << meddeviation(values, frequencies) << endl;
  cout << "Standardabweichung...: " << stddeviation(values, frequencies) << endl;

  return 0;
}
