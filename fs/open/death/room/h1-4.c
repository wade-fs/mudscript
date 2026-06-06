// Room: /open/death/room/h1-4
inherit ROOM;

void create ()
{
  set ("short", "第一殿--分屍地獄");
  set ("long", @LONG
你一走進這裡，便聽到陣陣的慘叫聲，放眼看去，只見生前拆散別
人骨肉，及破壞良家婦女名節的人，被鬼卒用木板前後夾住，然後拿鋸
子從頭往下鋸成兩半，霎時鮮血四濺，接著鬼卒再把屍體拖到一旁，縫
合後，澆上復活水使其復活，再重複剛剛的刑罰。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"h1-2",
]));
  set("light_up", 1);

  setup();
}
