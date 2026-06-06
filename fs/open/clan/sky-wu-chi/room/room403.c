inherit ROOM;
void create() {
	set( "short", "玄武上將軍府" );
	set( "owner", "poiiiiop" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/killer/obj/kill_yar_head",
		"file2"    : "/open/killer/obj/kill_yar_head",
		"amount1"  : 1,
	]) );
	set( "build", 10020 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room407",
	]) );
	set( "long", @LONG
與生俱來人中首 唯我與天同齊壽 雙腳踼翻塵世浪 一肩擔盡古今愁 
凌駕玄武九天翔 智謀非凡名聲揚 塵世濁浪不沾足 心傾竹音識長才 

         北方翠竹三月生，少年得意誰與爭。
         君臨天下齊天殿，揮戈直指玄都城。
         春秋家國天下事，紅塵濁浪一肩承。
         豈料驚龍斷天命，猜心園中盡悲風。

千經百戰、戰無不克，號稱『風之黑豹』的玄武上將軍 - 非凡公子
LONG);
	setup();
	replace_program(ROOM);
}
