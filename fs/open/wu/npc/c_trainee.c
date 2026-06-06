// trainee.c
// 武館弟子
inherit NPC;
void create()
{
        set_name("武館弟子", ({ "trainee" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "你看到一位身材高大的漢子﹐正在辛苦地操練著。\n");
        set("combat_exp",27000);
        set_temp("apply/attack",40);
        set_temp("apply/dodge",60);
        setup();
        carry_object(__DIR__"obj/linen")->wear();
}
