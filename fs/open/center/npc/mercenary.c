// rewriten from bully.c
// mercenary.c by powell

inherit NPC;
int do_say();
void create()
{
        set_name("鏢師", ({ "Mercenary","mercenary" }) );
        set("race", "人類");
        set("gender", "男性");
        set("age", 25);
        set("long","武威鏢局的鏢師,若非有一點本事,普通人在這是討不到飯吃的.\n"+
        "他正為了增進自己本身武學而辛勤的與別人對招.\n");
        set("cps", 5);
        set("str", 28);
        set("cor", 20);
        set("kar",10);
        set("spi", 1);

        set( "inquiry", ([
             "here" : "這兒是武威鏢局的總行,若沒什麼事就不要在此逗留."
             ]));               
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: this_object(),"do_say" :),
        "鏢師說道 : 這傢伙交給我就好了, 你們都別插手。\n",
         }) );
                
        set_temp("apply/attack", 1);
           set_skill("unarmed",40);
        set("combat_exp",280);
        setup();
        add_money("silver",3);
}

int do_say()
{
        object me=this_player();
        tell_room(environment(this_object()),
        "鏢師喝道﹕可惡!! "+RANK_D->query_rude(me)+"你是活的不耐煩了嗎? 竟敢來武威鏢局來撒野。\n");
}
        
void defeated_enemy(object ob)
{
        say("鏢師冷笑一聲道 : 沒本事也敢到這來撒野。\n");
        remove_killer(ob);
}        
