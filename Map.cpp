#include "Map.h"

Map::Map()
{
    int size = 10000;
    array_key = new string[size];
    array_value = new int[size];

    for(int i=0;i<size;i++)
        array_key[i]="";
}

int Map::funcionHash(string key, int rerun)
{
    int suma=0;
    for(int i=0;i<key.size();i++)
    {
        suma+=key[i];
    }
    return suma+rerun;
}


int Map::getIndex(string key)
{
    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key, rerun);
        rerun++;

        if(array_key[pos]== "")
            return -1;

    }while(array_key[pos]!=key);

    return pos;
}

void Map::put(string key, int value)
{
    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;
    }while(array_key[pos] != "~" && array_key[pos] != "");

    array_key[pos]=key;
    array_value[pos]=value;
}

int Map::get(string key)
{
    int pos = getIndex(key);
    if(pos!= -1)
        return array_value[pos];
    return -1;
}

bool Map::exists(string key)
{
    return !(getIndex(key) == -1);
}

void Map::remove(string key)
{
  int pos = getIndex(key);
  array_key[pos] = "~";
}
