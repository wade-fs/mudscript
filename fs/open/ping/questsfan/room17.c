// Room: /u/d/dhk/questsfan/room17
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "藍晶層");
  set ("long", @LONG
這一層位於谷緣的結晶都呈現藍色的光芒，所以顧名
思義這一層的結晶叫〝藍晶石 〞，因其顏色炫藍且無時無
刻的散發出另人憂鬱的氣息，會另你想起你一生的挫折，
心情鬱悶。你一路觀看過延途一層層各式各色的晶石，另
你感到致身於仙境中的感覺、眼花撩亂，忽而好極忽而鬱
悶…變的多愁善感。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room18",
  "eastup" : __DIR__"room16",
]));

  setup();
}
