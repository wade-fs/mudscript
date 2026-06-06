inherit ROOM;
void create() {
	set( "short", "花海" );
	set( "owner", "zeros" );
	set( "object", ([
		"file10"   : "/open/capital/obj/blade2",
		"file7"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/gsword/obj/spsword-4",
		"file8"    : "/open/gsword/obj/spsword-1",
		"file1"    : "/u/f/frequency/obj/icer",
		"file4"    : "/open/gsword/obj/silver_sword",
		"file2"    : "/open/love/obj/cloth1",
		"file9"    : "/open/capital/obj/blade2",
		"amount8"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/capital/obj/blade2",
		"amount2"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10082 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room119",
	]) );
	set( "long", @LONG
眼前一片無望無際的花中世界,可能就是維持湖居小築空氣芳香
的來源,你四處張望了一下發覺前面的花海中各種花的排列方式
似乎是依照五行八卦來組合的,止時你發覺在花海的中心有著一
座花神的神像,而神像的四周開著你不曾看過的奇異花種,想必那
就是讓只小島的空氣如止美好的主因吧.

LONG);
	setup();
	replace_program(ROOM);
}
