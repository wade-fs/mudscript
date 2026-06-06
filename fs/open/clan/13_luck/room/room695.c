inherit ROOM;
void create() {
	set( "short", "ddddd3" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
	]) );
	set( "build", 5003 );
	set( "light_up", 1 );
	set( "long", @LONG
華麗且具特色的建築群中,似乎有一間不起眼的破茅屋夾雜其中
你不經揉了揉眼睛,懷疑自己是否因為過度疲勞看到幻影了?好奇心
驅使之下,你不自覺的加快了腳步.但眼前所見卻令你瞠目結舌.眼前
的建築,也許只能勉強稱為建築吧.早已被蛀食一空的木料,散出陣陣
腐臭的味道屋頂只是簡陋的茅草,隱約還可以看到有被禽鳥啄食抓散
的痕跡,所謂的大門,不過就是兩片紙板勉強裝訂而成,你不由得深深
的懷疑了起來,誰有本事呆在這種鳥地方??


LONG);
	setup();
	replace_program(ROOM);
}
