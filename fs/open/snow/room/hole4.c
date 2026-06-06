#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
          set("long","這是一條相當狹隘的小路,陰風四起吹得你毛骨悚然,你只希望能早一點離開這條死氣沈沈的小路。\n");

        set("exits", ([
          "west":__DIR__"hole6",
          "east":__DIR__"hole1",
        ]) );
        setup();
}
