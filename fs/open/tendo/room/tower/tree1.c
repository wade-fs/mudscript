inherit ROOM;
#include <ansi.h>
void create()
{
set("short","松林");
set("long",@LONG
只見此地一大片的松樹林，枝枒參天，蔥翠墨綠，彷彿見不著邊
際，在路旁有著一塊告示牌( sign )，林中闢出一條小徑，直往著峰
頂通去。
LONG);
set("exits",([ /* sizeof() == 3 */
"down" : __DIR__"bridge1.c",
"up" : __DIR__"tree2.c",
]));
set("item_desc", ([
"sign":@TEXT
             此處列為～禁地～，踏入者後果自行負責。
                                               
                                             天道派
TEXT,
]) );
set("outdoors",1);
setup();

}


