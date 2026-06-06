#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "仙劍派石階");
        set("long", @LONG
你沿著石階往上走了一會，發現周圍的景色也有了不同的變化，仔細看
著兩旁樹木的排列，亂中有序，隱隱的透露出一股莊嚴的氣息，石階上是
一塵不染，令你心生嚮往。        
LONG
        );

        set("exits", ([
                "down":__DIR__"road4",
                "up":__DIR__"road7"
        ]) );
      set("light_up",1);
      set("outdoors","/open/gsword");
set("objects",([
               "/u/b/bigcat/mob/washboy":1]));

setup();

}
