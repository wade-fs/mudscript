// clone/npc/under_canal_hub_ferryman.c
// 擺渡盲叟 (under_canal_hub_ferryman) - 古暗渠樞紐

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("擺渡盲叟");
    set_short(HIC "暗渠溶洞" NOR " 擺渡盲叟");
    set_long("一位雙目枯槁、手撐一根九節鐵竹篙的白髮老叟，靜靜立於地下溶洞暗河的烏篷扁舟船頭。\n"
             "他彷彿已在城下太古暗渠中擺渡了數十年，僅憑水聲迴響便能辨別地下迷宮的每一條支流。\n");
    set_id(({ "under_canal_hub_ferryman", "ferryman", "blind ferryman", "擺渡盲叟", "擺渡叟" }));

    setup_archetype("J", 25);
    set("class", "mortal");
    set("faction", "jianghu");
    set("roles", ({ "service", "info" }));
    set("schedule", "24h");

    add_response(({ "暗渠", "擺渡", "史前殘殿", "天字一號", "水閘" }),
        "擺渡盲叟竹篙輕點水面，幽幽道：「向西順水可出廢棄水閘潛入外城護城河；向東是舊商盟塵封三十載的天字一號玄鐵門；向南則是萬年前大清洗遺留的史前殘殿……地煞噬人，好自為之。」");
}
