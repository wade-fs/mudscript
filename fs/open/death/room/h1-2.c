// Room: /open/death/room/h1-2
inherit ROOM;

void create ()
{
  set ("short", "第一殿--糞池地獄");
  set ("long", @LONG
你站在這裡，看到鬼卒用鐵叉戳穿罪人的身體，然後拋進糞池內，
被拋進糞池的人不斷的掙扎，但穢物卻不斷灌進他的孔竅，等他完全被
穢物所淹沒，鬼卒才把他從糞池抓起，把他倒吊著，等他吐清穢物後再
重複丟進糞池中。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"h1-4",
  "north" : __DIR__"h1-7",
]));
  set("light_up", 1);

  setup();
}
