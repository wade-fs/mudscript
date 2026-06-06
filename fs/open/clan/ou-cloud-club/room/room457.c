inherit ROOM;
void create() {
	set( "short", "魔劍丹藥室2" );
	set( "owner", "mekyn" );
	set( "build", 10364 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room456",
		"east"      : "/open/clan/ou-cloud-club/room/room458.c",
	]) );
	set( "long", @LONG


   Λ  Λ      Λ  Λ      Λ  Λ      Λ  Λ       Λ  Λ
  / ⊙⊙ \    / ヾ●-\    /-●●-\    /-●ゝ \     / ◎◎ \
 ( ≡ o≡ )  ( ≡∪≡ )  ( ≡∪≡ )  ( ≡∪≡ )   ( ≡o ≡ )
  ( 2cat )    ( 2cat )    ( 2cat )    ( 2cat )     ( 2cat ) 
    ▲ ▲ ～    ▲ ▲ ～    ▲ ▲ ～    ▲ ▲ ～     ▲ ▲ ～


LONG);
	setup();
	replace_program(ROOM);
}
