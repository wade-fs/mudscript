// Room: /u/s/sueplan/newplan/area/room9
inherit ROOM;

void create ()
{
  set ("short", "貪狼星");
  set ("long", @LONG
當殷商減亡，妲己也被姜尚所捕而處死，太白金星召來妲己的靈魂
，讓她永住貪狼星，掌管『慾望』。妲己本來是個狐狸妖精，險奸又狡
猾，是不應該被奉為女神的。但是當時天界少神，所以給地一個女神的
神位。
    太白金星又怕她做出許多害人的事，所以特地選擇由兇狼所圍住的
貪狼星作為牠的永住地點，不讓她走出外面，可見太白金星早有先見之
明。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"room8.c",
  "north" : __DIR__"room10.c",
]));

  setup();
}
