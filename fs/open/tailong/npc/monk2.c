 inherit NPC;
void create()
{
  set_name("知客僧",({"monk"}));
        set("gender","男性");
        set("class","scholar");
        set("combat_exp",5000);
        set("attitude","peaceful");
        set("age",23);
        set("chat_chance", 30);
        set("chat_msg", ({
        "知客僧說道: 施主您好,請問有什麼事。\n",
        "知客僧說道: 施主,您要找什麼人或什麼地方,問我就對了。\n",
        }));
        set("inquiry", ([
        "方丈" : "您往東或往西走,看到往北的路直直走就對了。",
        "段譽" : "這個嘛,段前輩現在住在玄機房隱居,不想有人打擾。",
        "本相" : "本相師父和其他幾位老師父正在牟尼院中清修,別打擾他們老人家了。",
        "牟尼堂" : "那是本寺的高僧清修之處,在本寺的西院。\n",
        "玄機房" : "那是段譽前輩夫婦居住的地方,就在寺裡的東院。\n",
        ]));
        set("force",500);
        set("max_force",500);
        set("max_kee",500);
        set("kee",500);
        set("force_factor", 1);
        set_skill("force",40);
        set_skill("unarmed",30);
        set_temp("apply/dodge",40);
        setup();
        add_money("silver",10);
       }
