inherit ROOM;
void create() {
	set( "short", "花海" );
	set( "build", 10099 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/nine-sky-dragon/room/room4",
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
