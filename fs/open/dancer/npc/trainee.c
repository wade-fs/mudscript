// trainee.c
// 練習生
inherit NPC;
void create()
{
        set_name("練習生", ({ "trainee" }) );
        set("gender", "女性" );
        set("age", 20);
        set("long", "妳看到的是夜夢小築的練習生\n");
        set("combat_exp",60000);
        set_temp("apply/attack",100);
        set_temp("apply/dodge",90);
        setup();
}
