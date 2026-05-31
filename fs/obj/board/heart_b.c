inherit BULLETIN_BOARD;

void create()
{
        set_name("心情故事板", ({ "board" }) );
        set("location", "/open/su/room/hotel");
        set("board_id", "heart_b");
        set("long",     "這是一個心情板....當你不爽,生氣,高興,
快樂,賭爛,鬱卒,被甩,甩人,被放鴿,被 pk 都可來這發洩一下..。\n" );
        setup();
        set("capacity", 30);
}
