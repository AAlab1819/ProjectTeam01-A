#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int arr1[], int low, int high);
void quicksort(int arr[], int arr1[], int low, int high);

void quickSort(int arr[], int arr1[], int low, int high)
{
    int pi;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        pi = partition(arr, arr1, low, high);

        quickSort(arr, arr1, low, pi - 1);  // Before pi
        quickSort(arr, arr1, pi + 1, high); // After pi
    }
}

int partition (int arr[], int arr1[], int low, int high)
{
    // pivot (Element to be placed at right position)
    int pivot = arr[high];

    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            temp = arr1[j];
            arr1[j] = arr1[i];
            arr1[i] = temp;
            //swap arr[i] and arr[j]
        }
    }
    int temp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = temp;
    temp = arr1[high];
    arr1[high] = arr1[i + 1];
    arr1[i + 1] = temp;
    //swap arr[i + 1] and arr[high])
    return (i + 1);
}

int main(){

    //coins fraction index in the array
    int FIVE_C = 0, TEN_C = 1, TWENTY_C = 2, FIFTY_C = 3, ONE_D = 4, TWO_D = 5;
    int coinSize = 6;
    //coins fraction values
    int allCoins[coinSize] = {5, 10, 20, 50, 100, 200};
    //flag to continue the input loop
    bool cont = true;
    //int count = 0;
    vector<int> answer;
    //loop while input flag is true
    while(cont){
        int ans = -1;
        int coins[6] = {0};
        float value = 0;
        cont = false;
        for(int i=0; i<6; ++i){
            cin >> coins[i];
            //check if all input is 0 (it means the input loop ends)
            if(coins[i] > 0){
                cont = true;
            }else if(!cont){
                cont = false;
            }
        }

        //enter the algorithm if input not zeros
        if(cont){
            ans = 0;
            //count += 1;
            cin >> value;
            value = value*100;

            while(value != 0){
                //array of differences and the array of the coins value index
                int diffs[coinSize] = {0};
                int diffsIndex[coinSize] = {0};
                //output invalid input if the value needed is smaller than 5 cents
                if(value<allCoins[FIVE_C]){
                    cout<<"invalid input."<<endl;
                }else{
                    int prevValue = 0;
                    //loop while value is larger than 0(when the value needed is not yet reached
                    //loop while value is smaller than 0 (when the value given as payment exceed the value needed so it require changes
                    while(value > 0 || value < 0){
                        cout<<value<<endl;
                        if(value > 0){
                            for(int i=0; i<coinSize; ++i){
                                int diff = value - allCoins[i];
                                if(diff<0){
                                    diff *= -1;
                                }
                                diffs[i] = diff;
                                diffsIndex[i] = i;
                            }
                            //sort differences from smallest to largest and sort the index
                            quickSort(diffs, diffsIndex, 0, coinSize-1);

                            for(int i=0; i<coinSize; ++i){
                                //reduce value with the coin that has the smallest difference with the value
                                if(coins[diffsIndex[i]]>0){
                                    value -= allCoins[diffsIndex[i]];
                                    --coins[diffsIndex[i]];
                                    ++ans;
                                    cout<<"remove coin: "<<allCoins[diffsIndex[i]]<<endl;
                                    break;
                                }
                            }
                            //check available coins if previous value does not change it means the coins is empty
                            bool empty = false;
                            if(prevValue == 0){
                                prevValue = value;
                            }else if(prevValue == value){
                                empty = true;
                            }else{
                                prevValue = value;
                            }
                            if(empty){
                                cout<<"coin not enough"<<endl;
                                value = 0;
                            }
                        }else if(value < 0){
                            int inValue = value*-1;
                            //create array of differences of value and coins fraction
                            for(int i=0; i<coinSize; ++i){
                                int diff = inValue - allCoins[i];
                                if(diff<0){
                                    diff *= -1;
                                }
                                diffs[i] = diff;
                                diffsIndex[i] = i;
                            }

                            prevValue = value;
                            //sort differences from smallest to largest and sort the index
                            quickSort(diffs, diffsIndex, 0, coinSize-1);

                            for(int i=0; i<coinSize; ++i){
                                //reduce value with the coin that has the smallest difference with the value, but because this loop return changes we want the value not to exceed zero when added by the coin fraction
                                if(inValue - allCoins[diffsIndex[i]] >= 0){
                                    value += allCoins[diffsIndex[i]];
                                    ++ans;
                                    cout<<"return coin: "<<allCoins[diffsIndex[i]]<<endl;
                                    break;
                                }
                            }



                        }
                    }
                }
            }
            //cout<<ans<<endl;
            //push the answer to vector of answer to be displayed later
            answer.push_back(ans);

        }else{
            value = 0;
        }
    }
    //display answer
    for(int i=0; i<answer.size(); ++i){
        cout<<answer[i]<<endl;
    }

    return 0;
}
