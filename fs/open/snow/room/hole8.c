#include <room.h>

inherit ROOM;

void create()
{
        set("short","房間");
         set("long","這是一間曾經經過精心設計的房間,然而現在已經廢棄了,由地上的灰塵可以知道,近幾年來,鮮少有人進出。\n");

        set("exits", ([
          "north":__DIR__"hole6",
        ]) );
        setup();
}
