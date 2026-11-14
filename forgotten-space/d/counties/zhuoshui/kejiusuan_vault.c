// /d/counties/zhuoshui/kejiusuan_vault.c
// 濁水縣 (Zhuoshui County) 房間 14/15：暗渠石室・老帳房柯九算藏身處 (對應卷二 Ch.65 舊商盟「雲記」手抄名冊)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("暗渠石室・柯九算藏身處");
    set_long("這間位於排石暗渠高處的乾燥密室，點著一盞微弱的防風鯨油燈。通寶當鋪\n"
             "濁水分號避禍失蹤的老帳房「柯九算」曾在此藏身。石案鐵盒內留存著蓋有「前朝舊盟\n"
             "度支副印」的《雲記行手抄名冊底單》——記載「雲記少東沈懷安、幼女沈雲妮（天星\n"
             "十四年大火失蹤）」，與沈泥貼身玉佩及府衙文承敬舊案底單形成三方互鎖！向西出室\n"
             "即回【廢棄排石暗渠・鐵柵水門】。\n");

    set_exits(([
        "west": "/d/counties/zhuoshui/old_canal_entry.c",
    ]));

    add_item("yunji_vault", "藏有蓋著『前朝舊盟度支副印』之《雲記行手抄名冊底單》的暗渠鐵盒。");
    set_is_outdoor(0);
    set("is_underground", 1);
    set_coordinate(7, 5, -1);
}
