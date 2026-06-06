// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short",HIY + "金風細雨樓外" + NOR);
set ("long","典雅富麗而神秘的高架層上，畫棟雕簷，香玄兩旁的柱上有宋學士
秦太虛寫的一副對聯云：" + HIG + "嫩寒鎖夢因春冷，芳氣襲人是酒香。" + NOR + "再旁
銅鉤上懸著大紅麗花軟簾，窗紗透粉香，簷下樑吊水晶玻璃銀光雪
浪燈，香屑佈地，金窗玉鑑，天地輝煌。
");



  set("exits", ([
            "enter" : __DIR__"a1",
            "north" : __DIR__"57",
                ]));
  set("objects", ([ 
  __DIR__"npc/gold-guard-out" : 5,
                  ]));        

        setup();
}
