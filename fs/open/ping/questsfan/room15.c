// Room: /u/d/dhk/questsfan/room15
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "黃晶層");
  set ("long", @LONG
這一層位於谷緣的結晶都呈現金色的光芒，所以顧名
思義這一層的結晶叫〝金晶石 〞，刺眼的金芒讓你快讓你
睜不開眼睛，四周迷漫著一股貴氣，使你產生一股不可一
世的霸氣。你一路觀看過延途一層層各式各色的晶石，另
你感到致身於仙境中的感覺、眼花撩亂，心情頓時開朗許
多。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room16",
  "southup" : __DIR__"room14",
]));

  setup();
}
