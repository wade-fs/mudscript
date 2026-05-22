// /item/badge_newbie.c
inherit "/std/badge";

void create() {
    ::create();
    set_name("新手證明徽章");
    set_long("這是一枚由冒險者公會頒發的徽章，象徵著你邁出了冒險的第一步。\n");
    set_id(({"badge", "newbie badge", "徽章"}));
}
