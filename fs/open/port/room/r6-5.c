// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","守衛隊辦公室");
  set ("long", @LONG
這裡是守衛隊隊頭辦公的地方 . 大廳後方掛了個御賜的匾額 
 , 寫著 [保境安民] 四個金字 . 守衛隊成立於十五年前楓林立
港 , 建城之時 , 身負著港口安全的使命 , 曾六次成功的擊退來
犯的倭寇 . 四年前朝廷在港邊建立水軍 , 守衛隊從此隸屬於水
軍總督府 , 負責維持楓林港的治安 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/port/room/r6-3",
]));
	set("objects",([
	"/open/port/npc/leader":1,
	]));

  setup();
}
