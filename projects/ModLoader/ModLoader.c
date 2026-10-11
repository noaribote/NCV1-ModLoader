#include "types.h"
#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"
#include "enums.h"
#include "vars.h"
#include "BackgroundOptions.h"
#include "functions.h"

// [testa] à tester

// Pistolet | ~WEAPON_PISTOL~
// Fusil d'assaut | ~WEAPON_ASSAULTRIFLE~
// Fusil à pompe | ~WEAPON_PUMPSHOTGUN~
// Mitraillette | ~WEAPON_SMG~
// Sniper | ~WEAPON_SNIPERRIFLE~
// RPG | ~WEAPON_RPG~
// Voiture | ~BLIP_CAR~
// Avion | ~BLIP_PLANE~
// Bateau | ~BLIP_BOAT~
// Argent | ~BLIP_CASH~
// Santé | ~BLIP_HEALTH~
// Gilet pare-balles | ~BLIP_ARMOR~


void MODELSmenus()
{
	DrawBackground(1);
	AddTitle("Models Menus");
	AddScriptOption("Models Design ~r~/!\\ ~s~", "DesignCharacter", 1024, Triangle, DpadLeft);
}

void OModloadersT()
{
	DrawBackground(3);
	AddTitle("ModLoaders");
	AddScriptOption("Exotic Trainer v5.5", "ExoticTrainer", 6304, L1, L3Press);
	AddScriptOption("Rockstar Games", "App7e", 2024, R1, Square);
	AddScriptOption("MAJESTIC", "Majesticv1", 1024, R3Press, DpadLeft);
}

void FAVOFreezeMenus()
{
	DrawBackground(3);
	AddTitle("Favorites");
	AddScriptOption("ULTRA (FREEZE) V7 ~r~/!\\ ~s~", "YoungAndCraZyPrivate", 1024, DpadLeft, DpadDown);
	AddScriptOption("DaNiIxFreeze", "FreezeMenuv1", 2024, L1, Square);
	AddScriptOption("AutoFullPedFreeze", "AutoFullPedFrz", 128, Cross, Cross);
}
void FreezeMenus()
{
	DrawBackground(7);
	AddTitle("Freeze Menus");
	AddSubmenuOption("> Favorites", (FAVOFreezeMenus));
	AddScriptOption("ULTRA (FREEZE) V7 ~r~/!\\ ~s~", "YoungAndCraZyPrivate", 1024, DpadLeft, DpadDown);
	AddScriptOption("V-_-Menu", "Vmenu", 1024, L1, R1);
	AddScriptOption("FZSPAM", "frz2", 1024, L1, R1);
	AddScriptOption("AutoFullPedFreeze", "AutoFullPedFrz", 128, Cross, Cross);
	AddScriptOption("V3ND3TT4", "abigail3", 1024, L1, R1);
	AddScriptOption("DaNiIxFreeze", "FreezeMenuv1", 2024, L1, Square);
}

void FAVOProtectMenus() {
	DrawBackground(3);
	AddTitle("Favorites");
	AddScriptOption("Unrestrained v8.0", "Unrestrained", 2024, L1, Square);
	AddScriptOption("Black Saint v5.0", "BProtectSaint", 2024, R3Press, DpadDown);
	AddScriptOption("LIMOX Protect", "SCRIPT", 1024, L1, R1);
}
void Protections()
{
	DrawBackground(14);
	AddTitle("Protection Menus");
	AddSubmenuOption("> Favorites", (FAVOProtectMenus));
	AddScriptOption("HELPER Menu", "HelperMenu", 1024, DpadLeft, Square);
	AddScriptOption("LIMOX Protect", "SCRIPT", 1024, L1, R1);
	AddScriptOption("SERENDIPITY PROTECTIONS", "Serendipity", 1024, R1, R3Press);
	AddScriptOption("ULTRA (PROTECT) V7 ~r~/!\\ ~s~", "YoungAndCraZyPrivate", 1024, DpadLeft, DpadDown);
	AddScriptOption("Black Saint v5.0", "BProtectSaint", 2024, R3Press, DpadDown);
	AddScriptOption("Unrestrained v8.0", "Unrestrained", 2024, L1, Square);
	AddScriptOption("XXX", "BunkerDEVS", 1024, L1, DpadDown);
	AddScriptOption("RFOoDxMoDz's", "RFOoDxMoDz", 1024, L1, DpadLeft);
	AddScriptOption("Private Protections", "PrivateProtections", 1024, Cross, DpadLeft);
	AddScriptOption("PROTECTIONS by Bandit", "protection", 1024, DpadRight, Square);
	AddScriptOption("AntiModderAttach", "AntiModderAttach", 1024, L3Press, Triangle);
	AddScriptOption("Anti Time Out", "timeout", 1024, Nothing, Nothing);
	AddScriptOption("FREEZE Protection", "frzprotex", 1024, Nothing, Nothing);
}

void OutfitMenus()
{
	DrawBackground(5);
	AddTitle("Outfit Menus");
	AddSubmenuOption("> Models Menus", (MODELSmenus));
	AddScriptOption("Random Outfit", "RandomOutfit", 1024, Nothing, Nothing);
	AddScriptOption("Godly Outfits (FYV7)", "Godly", 1024, L1, R1);
	AddScriptOption("JakeModz89 Outfits", "OutfitLoader", 1024, DpadDown, Circle);
	AddScriptOption("Saab Modz", "SaabRaame", 2024, L1, R1);
}

void FAVORecoveryMenus()
{
	DrawBackground(3);
	AddTitle("Favorites");
	AddScriptOption("SkipTutorialOnline", "csm_menu", 1024, L2, DpadDown);
	AddScriptOption("Insanity's Recovery", "Xx_INS4NO_xX", 1024, DpadLeft, DpadDown);
	AddScriptOption("JAMES REBORN 4.6", "JRrecovery", 1820, DpadRight, R3Press);
}
void Recovery()
{
	DrawBackground(14);
	AddTitle("Recovery Menus");
	AddSubmenuOption("> Favorites", (FAVORecoveryMenus));
	AddScriptOption("JAMES REBORN 4.6", "JRrecovery", 1820, DpadRight, R3Press);
	AddScriptOption("G-Recovery", "G_Recovery", 1024, DpadDown, L1);
	AddScriptOption("Insanity's Recovery", "Xx_INS4NO_xX", 1024, DpadLeft, DpadDown);
	AddScriptOption("2MUCH4U", "Recoveryv3", 512, R1, Cross);
	AddScriptOption("SkipTutorialOnline", "csm_menu", 1024, L2, DpadDown);
	AddScriptOption("DANIIXMODZ", "Recoveryv2", 1024, L1, Circle);
	AddScriptOption("Web Hacker Recovery", "WEB_Exclusive", 1024, R1, Cross);
	AddScriptOption("Stats EDITOR", "CR_Stat", 128, DpadDown, Circle);
	AddScriptOption("Garage EDITOR", "GarageEditor", 1024, DpadRight, Cross);
	AddScriptOption("Slinky's Recovery", "slinkytdbrecovery1", 1024, R1, Cross);
	AddScriptOption("CASH DROP", "cashdrop1", 1024, L1, DpadDown);
	AddScriptOption("D3AD3Ditzz RECOVERY", "D3ADRecovery", 1024, R1, Cross);
	AddScriptOption("Solo 1,5%", "armenian1", 6304, Nothing, Nothing);
}

void FunLocation() {
	DrawBackground(6);
	AddTitle("Fun Locations");
	AddScriptOption("TGSAUDOIZ MAPS", "TgsaudoizHouse", 1024, L1, Square);
	AddScriptOption("MAZE BANK Ramp", "mazebankrampv1.2", 1024, Nothing, Nothing);
	AddScriptOption("Japan Rhythm", "JapanRhythm", 1024, Nothing, Nothing);
	AddScriptOption("Jetty Tg", "JettyTg", 1024, Nothing, Nothing);
	AddScriptOption("Nuketown", "Black_ops2", 1024, Nothing, Nothing);
	AddScriptOption("Oasis Tali", "OasisTali", 1024, Nothing, Nothing);
}
void Teleport()
{
	DrawBackground(6);
	AddTitle("Teleport Menus");
	AddSubmenuOption("> Fun Locations", (FunLocation));
	AddScriptOption("Exotic Teleporter v4.1", "Teleporter", 1024, DpadLeft, Square);
	AddScriptOption("(UT) SonOfABeach", "franklinz", 1024, R1, Circle);
	AddScriptOption("Map Loader", "NYM_V2.1", 1024, R1, DpadRight);
	AddScriptOption("North Yankton Menu", "yankton_menu", 1024, DpadLeft, Cross);
	AddScriptOption("ULTIMATE TELEPORT", "Tgsaudoiz", 2024, R1, Circle);
}
void FunVehicMenus()
{
	DrawBackground(6);
	AddTitle("Fun Vehicles");
	AddScriptOption("Animated Plates", "AnimatedPlates", 1024, R1, DpadDown);
	AddScriptOption("Paint Menu", "paint_menu", 1024, R1, DpadLeft);
	AddScriptOption("Handling Editor", "Handling", 1024, R1, Cross);
	AddScriptOption("Remote Control (Cars)", "Remote_Control", 1024, R1, Cross);
	AddScriptOption("Rockstar Games", "App7e", 2024, R1, Square);
	AddScriptOption("Fun Cars LOADER", "FCLoader", 1024, DpadRight, R3Press);
}
void FunMenus()
{
	DrawBackground(20);
	AddTitle("Fun Menus");
	AddSubmenuOption("> Fun Locations", (FunLocation));
	AddSubmenuOption("> Fun Vehicles", (FunVehicMenus));
	AddScriptOption("JRInnocenceMenu", "JRInnocenceMenu", 3076, Triangle, DpadRight);
	AddScriptOption("Rockstar Games", "App7e", 2024, R1, Square);
	AddScriptOption("CUSTOM CAMERA", "Custom_Camera", 1024, R1, R3Press);
	AddScriptOption("Slinky's Animmations Menu", "slinky_anim1", 1024, R1, DpadRight);
	AddScriptOption("Particle Menu v3", "ParticleMenuV03", 1024, DpadRight, Square);
	AddScriptOption("Perspective FYV7 v2", "Perspectivemenu", 1024, DpadRight, Square);
	AddScriptOption("Drone Mode", "DroneMode", 1024, DpadLeft, Triangle);
	AddScriptOption("Rocket Car", "rocketcar", 1024, Nothing, L1);
	AddScriptOption("Homelander", "ProjectCL_LaserEyes", 128, Nothing, R1);
	AddScriptOption("Ironman", "ProjectCL_IronmanMode", 128, Nothing, R1);
	AddScriptOption("Hulk", "ProjectCL_HulkMode", 128, Nothing, L2);
	AddScriptOption("Car Jump", "Car_Jump", 1024, Nothing, Nothing);
	AddScriptOption("Superman", "sup4rm4n", 1024, Nothing, Nothing);
	AddScriptOption("Fuel Mod", "FuelMod", 1024, Nothing, Nothing);
	AddScriptOption("DeadShot V1", "DeadShotV1.1.1", 1024, Nothing, Nothing);
	AddScriptOption("Allah Hackbar", "Allah_Hackbar_V1", 1024, Nothing, Nothing);
	AddScriptOption("The Walking Dead", "ZombieMod", 512, Nothing, Nothing);
	AddScriptOption("LSPD Mod", "LSPDM0D", 1024, Nothing, Nothing);
}

void ESModMenus()
{
	DrawBackground(2);
	AddTitle("Spanish Mod Menus");
	AddScriptOption("~y~[SPANISH]~s~ AP II Intense", "APII_Spanish", 2024, R1, Square);
	AddScriptOption("~y~[SPANISH]~s~ Wilson RC", "Venom-_-W", 1024, DpadRight, Square);
}
void FRModMenus()
{
	DrawBackground(3);
	AddTitle("French Mod Menus");
	AddScriptOption("~y~[FRENCH]~s~ AP II Intence", "Ap_II_intense", 2024, R1, Square);
	AddScriptOption("~y~[FRENCH]~s~ NotYourDope's v6.6", "Inimitable", 1024, R1, DpadDown);
	AddScriptOption("~y~[FRENCH]~s~ K&K Dark Horse", "KKDarkHorse", 1024, L1, R1);
}
void FAVOModMenus()
{
	DrawBackground(3);
	AddTitle("Favorites");
	AddScriptOption("AP II Intense", "rock_menu2", 2024, R1, Square);
	AddScriptOption("NotYourDope's v6.6 ~r~/!\\ ~s~", "InimitableEN", 2024, R1, DpadDown);
	AddScriptOption("iLLuminate", "iLLuminate", 1024, DpadRight, Cross);
}
void ModMenus()
{
	DrawBackground(37);
	AddTitle("Mod Menus");
	AddSubmenuOption("> Favorites", (FAVOModMenus));
	AddSubmenuOption("> French Mod Menus", (FRModMenus));
	AddSubmenuOption("> Spanish Mod Menus", (ESModMenus));
	AddScriptOption("AP II Intense", "rock_menu2", 2024, R1, Square);
	AddScriptOption("AP II Intense (FreZzyGhost)", "FreZzyGhost", 1024, R1, Square);
	AddScriptOption("NotYourDope's v6.6 ~r~/!\\ ~s~", "InimitableEN", 2024, R1, DpadDown);
	AddScriptOption("NotYourDope's v5.9.2 ~r~/!\\ ~s~", "NotYourDope", 1024, R1, DpadDown);
	AddScriptOption("NotYourDope's v4", "NotYourDopeV4", 2024, R1, DpadDown);
	AddScriptOption("Samjase's Script", "apaktivator_32", 1024, DpadRight, R3Press);
	AddScriptOption("iLLuminate", "iLLuminate", 1024, DpadRight, Cross);
	AddScriptOption("GTA FUCKER", "GTAFUCKER", 1024, R1, Cross);
	AddScriptOption("Unity", "Unity", 1024, R1, R3Press);
	AddScriptOption("MK3 v1.6.2", "MK3Menu", 2024, R1, Square);
	AddScriptOption("MAJESTIC", "Majesticv1", 1024, R3Press, DpadLeft);
	AddScriptOption("TerraModz v3", "TerraModz", 2552, L2, R2);
	AddScriptOption("CONSOLE TRAINER V", "console_trainer_v", 1024, R1, DpadLeft);
	AddScriptOption("Expulsion", "DevScript", 1024, L1, Square);
	AddScriptOption("Alien Script", "ScriptA", 1024, R1, Square);
	AddScriptOption("X Script", "X_Script", 1024, R1, Square);
	AddScriptOption("ETERNAL DARKNESS", "BlackSaint", 6304, Cross, DpadDown);
	AddScriptOption("HUD Editor", "HudEditorv1", 1024, L1, Square);
	AddScriptOption("Button Bind menu", "Button_Bind", 1024, L3Press, Square);
	AddScriptOption("Destroy v3", "Destroy", 1024, R1, Cross);
	AddScriptOption("ProjectCL", "ProjectCL", 1024, DpadRight, Square);
	AddScriptOption("RaYRoD's Menu v4", "rayrod", 1024, L1, DpadRight);
	AddScriptOption("ArabicGuyUltra 2.6", "ArabicGuyUltra", 6304, DpadRight, Cross);
	AddScriptOption("Revolution", "Revolution", 1024, DpadRight, Square);
	AddScriptOption("Imperfect", "Imperfect", 1024, DpadRight, R3Press);
	AddScriptOption("Brodator", "Brodator", 1024, R3Press, DpadRight);
	AddScriptOption("FLEX V2.2", "flexv2.2", 1024, DpadLeft, Cross);
	AddScriptOption("K&K Dark Horse", "krank1", 1024, L1, R1);
	AddScriptOption("Three-Socks Trainer", "3Socks_Trainer", 2024, L1, Square);
	AddScriptOption("EXTREME PURGE V3", "purge", 2024, L1, DpadRight);
	AddScriptOption("Iron Menu", "Iron", 2024, DpadLeft, Cross);
	AddScriptOption("Insanity's Ultra", "insanityUltra", 6304, DpadLeft, DpadDown);
	AddScriptOption("Unknown", "Unknown", 1024, L1, Square);
	AddScriptOption("MINI MENYOO", "minimenyoo1", 1024, R1, DpadUp);
}
void Spawnermenus()
{
	DrawBackground(3);
	AddTitle("Spawner Menus");
	AddSubmenuOption("> Fun Vehicles", (FunVehicMenus));
	AddScriptOption("Erootiik Spawn", "erootiikspawn", 1024, DpadLeft, Square);
	AddScriptOption("Spawn Car v1", "Spawncarbandit", 1024, L1, Triangle);
}

void AllCSCscripts()
{
	DrawBackground(9);
	AddTitle("Menus");
	AddSubmenuOption("> Mod Menus", (ModMenus));
	AddSubmenuOption("> Fun Menus", (FunMenus));
	AddSubmenuOption("> Spawner Menus", (Spawnermenus));
	AddSubmenuOption("> Outfit Menus", (OutfitMenus));
	AddSubmenuOption("> Models Menus", (MODELSmenus));
	AddSubmenuOption("> Recovery Menus", (Recovery));
	AddSubmenuOption("> Teleport Menus", (Teleport));
    AddSubmenuOption("> Protection Menus", (Protections));
	AddSubmenuOption("> Freeze Menus", (FreezeMenus));
}

void FAVOall()
{
	DrawBackground(4);
	AddTitle("Favorites");
	AddSubmenuOption("> Favorite Mod Menus", (FAVOModMenus));
	AddSubmenuOption("> Favorites Recovery Menus", (FAVORecoveryMenus));
	AddSubmenuOption("> Favorites Protection Menus", (FAVOProtectMenus));
	AddSubmenuOption("> Favorites Freeze Menus", (FAVOFreezeMenus));
}

void InformationsLOADER()
{
	DrawBackground(6);
	AddTitle("Informations");
	AddOption("~b~Website:~s~ https://noachidxmb.xyz/");
	AddOption("~b~Discord:~s~ https://noachidxmb.xyz/discord");
	AddOption("NC V1 ModLoader: by Noa_chid");
	AddOption("NC V1 ModLoader: v2.1");
	AddOption("NC V1 ModLoader: 113 Scripts");
	AddOption("Base: NYD");
}
void NSFWBackgrounds() {
	DrawBackground(10);
	AddTitle("Background Changer");
	AddSettingsBgChanger("~r~[NSFW]~s~ Nike Pro 1", "classicvinewood_texture_1", "NCBG7");
	AddSettingsBgChanger("~r~[NSFW]~s~ Nike Pro 2", "classicvinewood_texture_2", "NCBG7");
	AddSettingsBgChanger("~r~[NSFW]~s~ Nike Pro 3", "classicvinewood_texture_3", "NCBG7");
	AddSettingsBgChanger("~r~[NSFW]~s~ Bella Poarch", "classicvinewood_texture_1", "NCBG4");
	AddSettingsBgChanger("~r~[NSFW]~s~ Mia", "classicvinewood_texture_2", "NCBG4");
	AddSettingsBgChanger("~r~[NSFW]~s~ Black Bikini - Front", "classicvinewood_texture_1", "NCBG9");
	AddSettingsBgChanger("~r~[NSFW]~s~ Black Bikini - Back", "classicvinewood_texture_2", "NCBG9");
	AddSettingsBgChanger("~r~[NSFW]~s~ Lucia", "classicvinewood_texture_2", "FYV7BG");
	AddSettingsBgChanger("~r~[NSFW]~s~ Good Meal", "classicvinewood_texture_3", "NCBG9");
	AddSettingsBgChanger("~r~[NSFW]~s~ After Job", "classicvinewood_texture_3", "NCBG4");
}
void ANIMEBackgrounds() {
	DrawBackground(5);
	AddTitle("Background Changer");
	AddSettingsBgChanger("Ken Kaneki", "classicvinewood_texture_1", "NCBG2");
	AddSettingsBgChanger("Madara Uchiwa", "classicvinewood_texture_3", "NCBG2");
	AddSettingsBgChanger("Super Saiyan Rosé", "classicvinewood_texture_2", "NCBG12");
	AddSettingsBgChanger("One Piece", "classicvinewood_texture_1", "NCBG3");
	AddSettingsBgChanger("Hunter X Hunter", "classicvinewood_texture_2", "NCBG5");
}
void FRBackgrounds() {
	DrawBackground(5);
	AddTitle("Background Changer");
	AddSettingsBgChanger("Noa_chid", "classicvinewood_texture_2", "NCBG6");
	AddSettingsBgChanger("Napoléon Ier", "classicvinewood_texture_3", "NCBG1");
	AddSettingsBgChanger("Bugatti Tourbillon", "classicvinewood_texture_3", "NCBG8");
	AddSettingsBgChanger("Concorde", "classicvinewood_texture_1", "NCBG10");
	AddSettingsBgChanger("Dassault Rafale", "classicvinewood_texture_1", "NCBG11");
}
void CarsBackgrounds() {
	DrawBackground(4);
	AddTitle("Background Changer");
	AddSubmenuOption("> French Content", (FRBackgrounds));
	AddSettingsBgChanger("Lamborghini 1", "classicvinewood_texture_3", "NCBG6");
	AddSettingsBgChanger("Lamborghini 2", "classicvinewood_texture_1", "NCBG8");
	AddSettingsBgChanger("BMW", "classicvinewood_texture_2", "NCBG8");
}
void TVBackgrounds() {
	DrawBackground(6);
	AddTitle("Background Changer");
	AddSettingsBgChanger("Death Trooper", "classicvinewood_texture_3", "FYV7BG");
	AddSettingsBgChanger("Venom & Carnage", "classicvinewood_texture_3", "NCBG10");
	AddSettingsBgChanger("Rick Grimes", "classicvinewood_texture_1", "NCBG1");
	AddSettingsBgChanger("Rick Grimes CRM", "classicvinewood_texture_1", "NCBG6");
	AddSettingsBgChanger("Walter White", "classicvinewood_texture_2", "NCBG1");
	AddSettingsBgChanger("Thomas Shelby", "classicvinewood_texture_3", "NCBG5");
}
void OtherBackgrounds() {
	DrawBackground(9);
	AddTitle("Background Changer");
	AddSettingsBgChanger("Ada Wong", "classicvinewood_texture_3", "NCBG11");
	AddSettingsBgChanger("Eminem", "classicvinewood_texture_2", "NCBG3");
	AddSettingsBgChanger("Pradschapate", "classicvinewood_texture_2", "NCBG11");
	AddSettingsBgChanger("Weed", "classicvinewood_texture_3", "NCBG3");
	AddSettingsBgChanger("Unknown", "classicvinewood_texture_3", "NCBG12");
	AddSettingsBgChanger("DevKit", "classicvinewood_texture_2", "NCIconsSPEC");
	AddSettingsBgChanger("Anonymous", "classicvinewood_texture_3", "NCIconsSPEC");
	AddSettingsBgChanger("PS5", "classicvinewood_texture_1", "NCBG5");
	AddSettingsBgChanger("PS3", "classicvinewood_texture_2", "NCBG10");
}

void BGChangerSub() {
	DrawBackground(9);
	AddTitle("Background Changer");
	AddSubmenuOption("> French Content", (FRBackgrounds));
	AddSubmenuOption("> Anime Content", (ANIMEBackgrounds));
	AddSubmenuOption("> Cars Content", (CarsBackgrounds));
	AddSubmenuOption("> TV Content", (TVBackgrounds));
	AddSubmenuOption("> Other Content", (OtherBackgrounds));
	AddSubmenuOption("> NSFW Content", (NSFWBackgrounds));
	AddSettingsBgChanger("Original", "classicvinewood_texture_1", "NCBG12");
	AddSettingsBgChanger("GTA VI Theme", "classicvinewood_texture_1", "FYV7BG");
	AddSettingsBgChanger("Lucia", "classicvinewood_texture_2", "NCBG2");
}
void OPAChangerSubBackground()
{
	DrawBackground(11);
	AddTitle("Background Opacity");
	AddOpacityButtonBG100("100% Background");
	AddOpacityButtonBG90("90% Background");
	AddOpacityButtonBG80("80% Background");
	AddOpacityButtonBG70("70% Background");
	AddOpacityButtonBG60("60% Background");
	AddOpacityButtonBG50("50% Background");
	AddOpacityButtonBG40("40% Background");
	AddOpacityButtonBG30("30% Background");
	AddOpacityButtonBG20("20% Background");
	AddOpacityButtonBG10("10% Background");
	AddOpacityButtonBG00("0% Background");
}
void OPAChangerSubScrollbar()
{
	DrawBackground(11);
	AddTitle("Scrollbar Opacity");
	AddOpacityButtonSB100("100% Scrollbar");
	AddOpacityButtonSB90("90% Scrollbar");
	AddOpacityButtonSB80("80% Scrollbar");
	AddOpacityButtonSB70("70% Scrollbar");
	AddOpacityButtonSB60("60% Scrollbar");
	AddOpacityButtonSB50("50% Scrollbar");
	AddOpacityButtonSB40("40% Scrollbar");
	AddOpacityButtonSB30("30% Scrollbar");
	AddOpacityButtonSB20("20% Scrollbar");
	AddOpacityButtonSB10("10% Scrollbar");
	AddOpacityButtonSB00("0% Scrollbar");
}
void OPAChangerSub()
{
	DrawBackground(2);
	AddTitle("Opacity Changer");
	AddSubmenuOption("> Background Opacity", (OPAChangerSubBackground));
	AddSubmenuOption("> Scrollbar Opacity", (OPAChangerSubScrollbar));
}
void NCXMBColorsBG() {
	DrawBackground(3);
	AddTitle("Banner Color");
	AddColorBanner01("~y~[Noa_chid's XMB]~s~ Magenta", false, 186, 44, 199, false);
	AddColorBanner01("~y~[Noa_chid's XMB]~s~ Grey", true, 29, 29, 29, false);
	AddColorBanner01("~y~[Noa_chid's XMB]~s~ Purple", false, 181, 149, 255, false);
}
void COLOhangerSubBanner()
{
	DrawBackground(10);
	AddTitle("Banner Color");
	AddSubmenuOption("> Noa_chid's XMB Colors", (NCXMBColorsBG));
	AddColorBanner01("White", false, 255, 255, 255, true);
	AddColorBanner01("Black", true, 0, 0, 0, false);
	AddColorBanner01("Red", true, 205, 0, 0, false);
	AddColorBanner01("Green", false, 0, 205, 0, false);
	AddColorBanner01("Blue", true, 0, 0, 205, false);
	AddColorBanner01("Pink", false, 255, 192, 203, false);
	AddColorBanner01("Brown", true, 139,69,19, false);
	AddColorBanner01("Yellow", false, 255,255,0, false);
	AddColorBanner01("Orange", false, 255,165,0, false);
}
void NCXMBColorsSB() {
	DrawBackground(3);
	AddTitle("Scrollbar Color");
	AddColorScrollbar01("~y~[Noa_chid's XMB]~s~ Magenta", false, 186, 44, 199);
	AddColorScrollbar01("~y~[Noa_chid's XMB]~s~ Grey", true, 29, 29, 29);
	AddColorScrollbar01("~y~[Noa_chid's XMB]~s~ Purple", false, 181, 149, 255);
}
void COLOhangerSubScrollbar() {
	DrawBackground(10);
	AddTitle("Scrollbar Color");
	AddSubmenuOption("> Noa_chid's XMB Colors", (NCXMBColorsSB));
	AddColorScrollbar01("White", false, 255, 255, 255);
	AddColorScrollbar01("Black", true, 0, 0, 0);
	AddColorScrollbar01("Red", true, 205, 0, 0);
	AddColorScrollbar01("Green", false, 0, 205, 0);
	AddColorScrollbar01("Blue", true, 0, 0, 205);
	AddColorScrollbar01("Pink", false, 255, 192, 203);
	AddColorScrollbar01("Brown", true, 139,69,19);
	AddColorScrollbar01("Yellow", false, 255,255,0);
	AddColorScrollbar01("Orange", false, 255,165,0);
}
void COLOhangerSub()
{
	DrawBackground(2);
	AddTitle("Color Changer");
	AddSubmenuOption("> Banner Color", (COLOhangerSubBanner));
	AddSubmenuOption("> Scrollbar Color", (COLOhangerSubScrollbar));
}
void SettingsPage() {
	DrawBackground(6);
	AddTitle("Settings");
	AddSubmenuOption("> Background Changer", (BGChangerSub));
	AddSubmenuOption("> Opacity Changer", (OPAChangerSub));
	AddSubmenuOption("> Color Changer", (COLOhangerSub));
	AddGlareDrawedOption("Draw Glare");
	AddLeftSidedOption("Left Side");
	AddScriptOption("Coordinates", "xyzh_coords1", 1024, Nothing, Nothing);
}

void MainMenu()
{
	DrawBackground(8 + CustomScriptCount + AddCustomScript);
	AddTitleNCV1("SetIcon", "NC V1");
	AddSubmenuOption("> https://noachidxmb.xyz/", (InformationsLOADER));
	AddSubmenuOption("> Favorite Menus", (FAVOall));
	AddSubmenuOption("> All Menus", (AllCSCscripts));
	AddSubmenuOption("> ModLoaders", (OModloadersT));
	// [testa] phase de test
	AddScriptOption("~WEAPON_PISTOL~ YY AP II Intense", "rock_menu2", 2024, R1, Square);
	AddScriptOption("(UT) SonOfABeach", "franklinz", 1024, R1, Circle);
	AddScriptOption("Insanity's Recovery", "Xx_INS4NO_xX", 1024, DpadLeft, DpadDown);
	AddScriptOptionNoBinds(CustomScript1, &CustomScript1StackSize);
    AddScriptOptionNoBinds(CustomScript2, &CustomScript2StackSize);
	AddScriptOptionNoBinds(CustomScript3, &CustomScript3StackSize);
	AddScriptOptionNoBinds(CustomScript4, &CustomScript4StackSize);
	AddScriptOptionNoBinds(CustomScript5, &CustomScript5StackSize);
	AddScriptOptionNoBinds(CustomScript6, &CustomScript6StackSize);
	AddScriptOptionNoBinds(CustomScript7, &CustomScript7StackSize);
	AddScriptOptionNoBinds(CustomScript8, &CustomScript8StackSize);
	AddScriptOptionNoBinds(CustomScript9, &CustomScript9StackSize);
	AddScriptOptionNoBinds(CustomScript10, &CustomScript10StackSize);
    if (AddCustomScript)
	{
		AddCustomScriptOption();
	}
	if (AlreadySetup)
	{
		DrawInstructionalButtons();
	}
	AddSubmenuOption("> Settings", (SettingsPage));
}

void MenuClosed()
{
	if (BindHint)
	{
		BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Welcome ! Press ~INPUT_FRONTEND_LS~ + ~INPUT_FRONTEND_RS~ to open ~b~NC V1~s~ ~g~www.noachidxmb.xyz~s~");
		END_TEXT_COMMAND_DISPLAY_HELP(0, 0, 0, -1);
	}
	if (IS_DISABLED_CONTROL_PRESSED(0, Bind1) && IS_DISABLED_CONTROL_JUST_PRESSED(0, Bind2))
	{
		PlayMenuSound("COLLECTED");
		CurrentSubmenu = (MainMenu);
		CurrentOption = 1;
		ScrollbarCoord = 0.0f;
		BindHint = false;
	}
}

void MenuOpen()
{
	DisableControls();
	if (IS_DISABLED_CONTROL_JUST_PRESSED(0, 178))
	{
		PlayMenuCrossBackSound("FocusIn");
		if (CurrentSubmenu == (MainMenu))
		{
			CurrentSubmenu = (MenuClosed);
			DisableCinematicCameraTimer = GET_GAME_TIMER() + 750;
			if (HAS_SCALEFORM_MOVIE_LOADED(GlareHandle))
			{
				SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&GlareHandle);
			}
			if (HAS_SCALEFORM_MOVIE_LOADED(InstructionalButtonsHandle))
			{
				SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&InstructionalButtonsHandle);
			}
		}
		else
		{
			SubmenuLevel--;			
			CurrentSubmenu = LastSubmenu[SubmenuLevel];
			CurrentOption = LastOption[SubmenuLevel];
		}
	}
	else if (IsControlPressed(202))
	{
		// PlayMenuDPADSound("NAV_UP_DOWN");
		PlayMenuSound("TENNIS_POINT_WON");
		if (CurrentOption == 1)
		{
			CurrentOption = SubmenuOptionCount;
		}
		else
		{
			CurrentOption--;
		}
	}
	else if (IsControlPressed(203))
	{
		PlayMenuSound("TENNIS_POINT_WON");
		// PlayMenuDPADSound("NAV_UP_DOWN");
		if (CurrentOption == SubmenuOptionCount)
		{
			CurrentOption = 1;
		}
		else
		{
			CurrentOption++;
		}
	}
}


		
void OtherLoops()
{
	if (CurrentSubmenu == (MenuClosed) && DisableCinematicCameraTimer > GET_GAME_TIMER())
	{
		setGlobalAtIndex(13245 + 4621, GET_GAME_TIMER());
		SET_INPUT_EXCLUSIVE(0, 178);
	}
	Hash StatHash = GET_HASH_KEY("MPPLY_NO_MORE_TUTORIALS");
	bool stat;
	bool StatGetStatus = STAT_GET_BOOL(StatHash, &stat, 0);
	if (!(StatGetStatus == 0))
	{
		if (!(stat == 1))
		{
			STAT_SET_BOOL(StatHash, 1, 0);
		}
	}
	if (!(AllowCustomScripts == 0))
	{
		if (CustomScriptCount < 10)
		{
			AddCustomScript = true;
		}
		else
		{
			AddCustomScript = false;
		}
	}
	if (!(ScriptToLoad == false))
	{
		if (AlreadyRequested == 0)
		{
			REQUEST_SCRIPT(ScriptToLoad), AlreadyRequested = true;
		}
		if (HAS_SCRIPT_LOADED(ScriptToLoad))
		{
			START_NEW_SCRIPT(ScriptToLoad, ScriptToLoadStackSize);
			SET_SCRIPT_AS_NO_LONGER_NEEDED(ScriptToLoad);
			ScriptToLoad = false;
			AlreadyRequested = false;
		}
	}
	if (KeyboardMonitoring)
	{
		if (!(UPDATE_ONSCREEN_KEYBOARD() == 0))
		{
			const char* KeyboardResult = GET_ONSCREEN_KEYBOARD_RESULT();
			if (!(IS_STRING_NULL_OR_EMPTY(KeyboardResult)))
			{
				SetKeyboardResultIntoOption(KeyboardResult);
				UpdateCustomScriptCount();
				UpdateCurrentOption();
				KeyboardMonitoring = false;
			}
		}
	}
}

void main()
{
	if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(GET_THIS_SCRIPT_NAME())) == 1)
	{
	    CurrentSubmenu = (MenuClosed);
	    MaybeLoadTexture("commonmenu");
	    MaybeLoadTexture("erootiik");
	    while (true)
	    {
		    OtherLoops();
		    if (!(IS_WARNING_MESSAGE_ACTIVE() || IS_PAUSE_MENU_ACTIVE()))
		    {
			    void (*function)() = CurrentSubmenu;
			    function();
			    if (!(CurrentSubmenu == (MenuClosed)))
			    {
				    MenuOpen();
			    }
		    }
		    WAIT(0);
	    }
	}
}