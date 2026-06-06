inherit ROOM;
void create() {
	set( "short", "$HIW$亡$HIR$劍$HIB$塚$NOR$" );
	set( "object", ([
		"file5"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 5,
		"file8"    : "/open/gsword/obj1/kring",
		"amount9"  : 41,
		"amount7"  : 1,
		"amount4"  : 66,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount6"  : 44,
		"amount8"  : 1,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 91,
		"amount5"  : 15,
		"file7"    : "/obj/gift/shenliwan",
		"amount2"  : 124,
		"file2"    : "/open/fire-hole/obj/k-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 10125 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room246.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
踏入此處瀰漫著一股肅殺的氣憤，地上插滿了各式各樣的斷劍
，看來彷彿是一個劍塚，在不遠處立了一個石碑，上面寫著此乃
劍聖=>(真‧樹頭)所葬劍之地，畢生所用之劍皆在此處，特此立
此石碑為之弔祭！你帶著景仰的神情為此感到淒壯的氣氛。
LONG);
	setup();
	replace_program(ROOM);
}
