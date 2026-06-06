inherit ROOM;
void create() {
	set( "short", "$BGRN$赫夫帕夫$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room186.c",
		"south"     : "/open/clan/time-limit/room/room24.c",
		"east"      : "/open/clan/time-limit/room/room204",
		"west"      : "/open/clan/time-limit/room/room79.c",
	]) );
	set( "long", @LONG
赫夫帕夫的代表動物是獺,溫柔和藹的赫夫帕夫,成長於寬闊溪谷,創辦了赫夫
帕夫學院,那裡的人既正直又忠貞,耐力十足的赫夫帕夫誠實無欺,且不畏任何
勞苦艱辛,赫夫帕夫本著有教無類的精神,接受所有的學生,教導學生合作與忠
誠來突破障礙

LONG);
	setup();
	replace_program(ROOM);
}
