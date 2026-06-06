inherit ROOM;
void create() {
	set( "short", "$HIR$果$HIC$凍$HIY$海$NOR$" );
	set( "object", ([
		"file3"    : "/open/ghost-hole/obj/light-spirit",
		"file1"    : "/open/ghost-hole/obj/fire-spirit",
		"amount3"  : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount1"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10074 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room505.c",
		"north"     : "/open/clan/ou-cloud-club/room/room447.c",
		"up"        : "/open/clan/ou-cloud-club/room/room536",
	]) );
	set( "long", @LONG
火龍幻界內傳來吱～吱～聲的垂死哀嚎，一代幻界霸主就此殞落！
火龍王心有不甘的吐出最後一口怨氣：剛強！你別得意....來世...我一定...會找你...報....仇...的....
聚靈山莊的封靈祭臺忽然劇烈的震動了起來!!
連在遠處的人們都能夠感受到這股大地的震動!!
封靈祭臺在吸滿五色靈器的靈力之後，釋放出強大的光芒散射四方!!
光芒散射整個大地，大地因為光芒的照耀而顯得生機盎然!!
LONG);
	setup();
	replace_program(ROOM);
}
