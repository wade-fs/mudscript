// Room: /open/death/room/lake
inherit ROOM;

void create ()
{
  set ("short", "血湖");
  set ("long", @LONG
走進這裡，一股腥穢無比的氣味撲鼻而來，呈現在你眼前的是一個
血所構成的湖，湖中傳來陣陣的哀嚎聲，一些產亡婦人正被鬼卒丟入湖
中。
LONG);

  set("light_up", 1);
  set("outdoors", "/open/death");

  setup();
}
