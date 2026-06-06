///open/prayer/room/hole/16.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	此處充滿黃色瘴氣，在這待的愈久，愈使人暈眩，麻痺，令人匪夷
	所思的是，這瘴氣好像停留在半空不散!!一些零零散散的白骨呈現
	在你眼前，看來這些魔獸不只吃肉，還喜歡啃骨頭，若是沒十分本
	事，下一具屍首很可能會是自己......

LONG	);
 
    set("objects", ([ /* sizeof() == 2 */
   "/open/prayer/npc/crab-ox" : 1,		
   "/open/prayer/npc/carapace-bee" : 1,		
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"14",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
