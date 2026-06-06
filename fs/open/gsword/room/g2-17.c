// Room: /open/gsword/room/gsword5-23.c
inherit ROOM;

void create ()
{
  set ("short", "帳房");
	set( "build", 120 );
  set ("long", @LONG
這裡是仙劍派的帳房，仙劍派上上下下將近千餘人眾，每日的開銷皆是一
筆巨大金額，好在仙劍派向來行俠仗義，名間聲望極高，往往有許多富翁
巨賈捐錢贊助，是以仙劍派不但無金錢問題，反而常救濟窮寒人家。左首
有個櫃臺上面放了個白玉算盤，右邊是個櫃子，裡面擺滿了帳簿。這裡充
現在是由仙劍七俠中的梅影女俠掌管。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/gsword/room/g2-15.c",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/swordsman/mayying" :1,
  "/open/gsword/npc/langirl" :1,
]));

  setup();
}
