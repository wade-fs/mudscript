inherit NPC;
void create()
{
    set_name("邪惡毛毛蟲",({"demon bug","bug"}) );
    set("gender", "男性");
    set("age",1);
   set("attitude","aggressive");
    set("long", "魔界跑出來的毛毛蟲, 長相醜惡, 讓人想要一拳打扁他 \n");
    set("kee",600);
    set("max_kee",600);
    set("combat_exp",800);
    setup();
}
