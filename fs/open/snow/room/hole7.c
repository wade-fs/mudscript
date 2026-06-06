#include <room.h>

inherit ROOM;

void create()
{
        set("short","禁閉室");
          set("long","這是一間禁閉室,四周打掃得一塵不染,你看到牆上寫著
             忍                   退
             一                   一
             時                   步
             風                   海
             平                   闊
             浪                   天
             靜                   空

這幾個字是用來規勸門下觸犯門歸弟子,而看到那毛筆自竟然能入石三分,你不禁對寫這對詞的武林高手敬佩不已。\n");

        set("exits", ([
          "east":__DIR__"hole6",
        ]) );

        create_door("east", "漆黑牢門", "west", DOOR_CLOSED);

        set("objects", ([ /* sizeof() == 3 */
         "/open/snow/npc/linhwi" :1,
         ]));
         setup();
}
