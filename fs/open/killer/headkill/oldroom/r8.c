inherit ROOM;


void create()

{
  
	set ("short", "殺手練習室");
  
	set ("long", @LONG

		這是初級殺手訓練的地方

		想要成為好的殺手必須經過不斷的鍛鍊

		而這裡便是培育優良殺手的房間之一



看來這裡是當年的另一間訓練室了，根據葉秀殺所說，
當年殺手就只有這些房間而已，看來真是夠小的幫派呀！！
（殺手的創幫原因請看help killer.create）
LONG);

  
	set("light_up", 100);
	set("no_magic", 10);
  
	set("exits", ([ /* sizeof() == 1 */

        "north":__DIR__"r5",
	
]));
  
/*
set("objects",([
	
	"open/killer/npc/trainee1" :3, 
		]));
 
*/
	setup();

}
