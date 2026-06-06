inherit ROOM;
void create() {
	set( "short", "$YEL$凌微雲扇飄$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 10300 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room693",
		"west"      : "/open/clan/ou-cloud-club/room/room691.c",
	]) );
	set( "long", @LONG

$YEL$凌微雲扇飄凌微雲扇飄凌微雲扇飄凌微雲扇飄$NOR$
$YEL$凌微雲扇飄凌微雲扇飄凌微雲扇飄凌微雲扇飄$NOR$
$YEL$凌微雲扇飄凌微雲扇飄凌微雲扇飄凌微雲扇飄$NOR$
$YEL$凌微雲扇飄凌微雲扇飄凌微雲扇飄凌微雲扇飄$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
