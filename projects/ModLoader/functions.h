void PlayMenuSound (const char* Sound)
{
	PLAY_SOUND_FRONTEND(-1, Sound, "HUD_AWARDS", true);
}

void PlayMenuDPADSound (const char* Sound)
{
	PLAY_SOUND_FRONTEND(-1, Sound, "HUD_FRONTEND_DEFAULT_SOUNDSET", true);
}

void PlayMenuCrossBackSound (const char* Sound)
{
	PLAY_SOUND_FRONTEND(1, Sound, "HintCamSounds", true);
}

bool IsControlPressed(int button)
{
	bool buttonPress = false;
	if (IS_DISABLED_CONTROL_JUST_PRESSED(0, button))
	{
		buttonPress = true;
	}
	else if (IS_DISABLED_CONTROL_PRESSED(0, button))
	{
		ScrollTimer++;
		if (!(ScrollTimer <= 4))
		{
			buttonPress = true;
			ScrollTimer = 1;
		}
	}
	else if (IS_DISABLED_CONTROL_JUST_RELEASED(0, button))
	{
		ScrollTimer = 0;
	}
	return buttonPress;
}

bool WasXJustPressed()
{
	bool buttonPress = false;
	if (CurrentOption == OptionCount)
	{
		if (!(IS_DISABLED_CONTROL_PRESSED(0, 202) || IS_DISABLED_CONTROL_PRESSED(0, 203)))
		{
			if (IS_DISABLED_CONTROL_JUST_PRESSED(0, 177))
			{
				PlayMenuCrossBackSound("FocusOut");
				buttonPress = true;
			}
		}
	}
	return buttonPress;
}

float GetSafezoneSizeHalfed()
{
	float safezoneSize = GET_SAFE_ZONE_SIZE();
	return safezoneSize / 2;
}

void SetMenuPosition(bool LeftSided)
{
	if (LeftSided)
	{
		MenuXCoord1 = 0.5061f - GetSafezoneSizeHalfed();
		MenuXCoord2 = 0.7211f - GetSafezoneSizeHalfed();
		MenuXCoord3 = 0.6136f - GetSafezoneSizeHalfed();
	}
	else
	{
		MenuXCoord1 = 0.2789f + GetSafezoneSizeHalfed();
		MenuXCoord2 = 0.4939f + GetSafezoneSizeHalfed();
		MenuXCoord3 = 0.3864f + GetSafezoneSizeHalfed();
	}
}	
	
void DrawGlare()
{
	GlareHandle = REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");
	if (HAS_SCALEFORM_MOVIE_LOADED(GlareHandle))
	{
		DRAW_SCALEFORM_MOVIE(GlareHandle, vector2((MenuXCoord2 + 0.23f), (0.9647f - GetSafezoneSizeHalfed())), Size(1.0f, 1.0f), RGBA(255, 255, 255, 255), 0);
	}
}

void StringBase(int font, int r, int g, int b, bool outline)
{
	SET_TEXT_FONT(font); // [testa] à tester
	SET_TEXT_SCALE(0.0f, 0.5f);
	SET_TEXT_COLOUR(RGBA(r, g, b, 255));
	SET_TEXT_WRAP(0.0f, MenuXCoord2);
	SET_TEXT_CENTRE(0);
	if (outline)
	{
		SET_TEXT_OUTLINE();
	}
}

void StringBasewithA(int font, int r, int g, int b, int a, bool outline)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(0.0f, 0.5f);
	SET_TEXT_COLOUR(RGBA(r, g, b, a));
	SET_TEXT_WRAP(0.0f, MenuXCoord2);
	SET_TEXT_CENTRE(0);
	if (outline)
	{
		SET_TEXT_OUTLINE();
	}
}

void MaybeLoadTexture(const char* TextureDict)
{
	if (!HAS_STREAMED_TEXTURE_DICT_LOADED(TextureDict))
	{
		REQUEST_STREAMED_TEXTURE_DICT(TextureDict, true);
	}
}

float SmoothScroll(float destinationCoord, float currentCoord)
{
	float newCoord = destinationCoord;
	if (!(currentCoord == 0.0f))
	{
		if (destinationCoord < currentCoord)
		{
			if (!(currentCoord - destinationCoord <= 0.007f))
			{
				newCoord = currentCoord - (currentCoord - destinationCoord) / 1.7f;
			}
		}
		if (destinationCoord > currentCoord)
		{
			if (!(destinationCoord - currentCoord <= 0.007f))
			{
				newCoord = currentCoord + (destinationCoord - currentCoord) / 1.7f;
			}
		}
	}
	return newCoord;
}

void AddTitle(const char* Title)
{
	StringBase(TitleFont, TitleR, TitleG, TitleB, TextOutlineTitle);
	SET_TEXT_CENTRE(true);
	SET_TEXT_SCALE(0.0f, 0.9f);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Title);
	END_TEXT_COMMAND_DISPLAY_TEXT(vector2(MenuXCoord3, (0.5346f - GetSafezoneSizeHalfed())));
	OptionCount = 0;
}

void SPRITE(char* TextOne, char* TextTwo, float X, float Y, float Width, float Height, float Rotation, int R, int G, int B, int A)
{
	MaybeLoadTexture(TextOne);
	if (HAS_STREAMED_TEXTURE_DICT_LOADED(TextOne))
	{
	DRAW_SPRITE(TextOne, TextTwo, vector2(X, Y), Size(Width, Height), Rotation, RGBA(R, G, B, A));
	}
}

void AddTitleNCV1(const char* SetIcon, char* Title)
{
	StringBasewithA(TitleFont, TitleRmain, TitleGmain, TitleBmain, TitleAmain, TextOutlineTitle);
	SET_TEXT_CENTRE(true);
	SET_TEXT_SCALE(0.0f, 0.9f);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Title);
	END_TEXT_COMMAND_DISPLAY_TEXT(vector2(MenuXCoord3, (0.5346f - GetSafezoneSizeHalfed())));
	OptionCount = 0;

	float OptionCountFloat; //                      set position y
	TitleCoord = (OptionCountFloat * 0.035f / 2.0f) + (0.5625f - GetSafezoneSizeHalfed());
	if(Enable_Title)
	{
		TitleAmain = 0;
		SPRITE(Title_File, Title_Name, MenuXCoord3, TitleCoord, 0.1250f, 0.0750f, 0, 255, 255, 255, ClarityTitle);
	}
}

void DrawBackground(int NumberOfOptions)
{
	float OptionCountFloat;
	float ScrollbarCoordStartingPoint;
	float ScrollbarDestinationCoord;
	SetMenuPosition(LeftSided);
	SubmenuOptionCount = NumberOfOptions;
	if (NumberOfOptions > 13)
	{
		OptionCountFloat = 13.0f;
	}
	else
	{
	    OptionCountFloat = NumberOfOptions;
	}
	BackgroundCoord = (OptionCountFloat * 0.035f / 2.0f) + (0.6146f - GetSafezoneSizeHalfed());
	// BackgroundCoord = (OptionCountFloat * 0.035f / 2.0f) + (0.6046f - GetSafezoneSizeHalfed());
	BackgroundLength = OptionCountFloat * 0.035f;
	if(Enable_Background)
	{
	SPRITE( Background_File, Background_Name, MenuXCoord3, BackgroundCoord, 0.2250f, BackgroundLength, 0, 255, 255, 255, Clarity);
	}
	DRAW_RECT(vector2(MenuXCoord3, BackgroundCoord), Size(0.2250f, BackgroundLength), RGBA(BackgroundR, BackgroundG, BackgroundB, BackgroundA));
	DRAW_RECT(vector2(MenuXCoord3, (0.5596f - GetSafezoneSizeHalfed())), Size(0.2250f, 0.09f), RGBA(BannerR, BannerG, BannerB, BannerA));
	if (GlareToggle)
	{
		DrawGlare();
	}
	BottomBarCoord = ((OptionCountFloat + 1.0f) * 0.035f) + (0.6071f - GetSafezoneSizeHalfed());
	// BottomBarCoord = ((OptionCountFloat + 1.0f) * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
	DRAW_RECT(vector2(MenuXCoord3, BottomBarCoord), Size(0.2250f, 0.035f), RGBA(BannerR, BannerG, BannerB, BannerA));
	if (OptionCountDisplay)
	{
		StringBase(OptionCountFont, OptionCountR, OptionCountG, OptionCountB, TextOutlineOptionCount);
		SET_TEXT_RIGHT_JUSTIFY(true);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("CM_ITEM_COUNT");
		ADD_TEXT_COMPONENT_INTEGER(CurrentOption);
		ADD_TEXT_COMPONENT_INTEGER(SubmenuOptionCount);
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2(0.0f, (BottomBarCoord - 0.018f)));
	}
	if (ScrollArrows && (ScrollArrowsAlways || !(SubmenuOptionCount <= 13)))
	{
		MaybeLoadTexture("commonmenu");
		if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
		{
			DRAW_SPRITE("commonmenu", "shop_arrows_upanddown", vector2(MenuXCoord3, BottomBarCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(ScrollArrowsR, ScrollArrowsG, ScrollArrowsB, 255));
		}
	}
	if ((CurrentOption < 7) || (SubmenuOptionCount <= 13))
	{
		ScrollbarCoordStartingPoint = CurrentOption;
	}
	else if ((SubmenuOptionCount - CurrentOption) < 6)
	{
		ScrollbarCoordStartingPoint = 13 - (SubmenuOptionCount - CurrentOption);
	}
	else 
	{
		ScrollbarCoordStartingPoint = 7;
	}
	ScrollbarDestinationCoord = (ScrollbarCoordStartingPoint * 0.035f) + (0.5971f - GetSafezoneSizeHalfed());
	// ScrollbarDestinationCoord = (ScrollbarCoordStartingPoint * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
	ScrollArrowsCoord = ScrollbarDestinationCoord;
    if (SmoothScrolling)
	{
		ScrollbarCoord = SmoothScroll(ScrollbarDestinationCoord, ScrollbarCoord);
	}
	else
	{
		ScrollbarCoord = ScrollbarDestinationCoord;
	}
    DRAW_RECT (vector2(MenuXCoord3, ScrollbarCoord), Size(0.2250f, 0.035f), RGBA(ScrollbarR, ScrollbarG, ScrollbarB, ScrollbarA));
}	

void DisableControls()
{
	if (DisableSpecialAbility)
	{
		if (IS_SPECIAL_ABILITY_ACTIVE(PLAYER_ID()))
		{
			SPECIAL_ABILITY_DEACTIVATE_FAST(PLAYER_ID());
		}
	}
	if (GET_PED_STEALTH_MOVEMENT(PLAYER_PED_ID()))
	{
		SET_PED_STEALTH_MOVEMENT(PLAYER_PED_ID(), 0, 0);
	}
	setGlobalAtIndex(10434 + 1, 0);
	setGlobalAtIndex(13245 + 4621, GET_GAME_TIMER());
	SET_CINEMATIC_MODE_ACTIVE(0);
	HIDE_HELP_TEXT_THIS_FRAME();
	HIDE_HUD_COMPONENT_THIS_FRAME(6);
	HIDE_HUD_COMPONENT_THIS_FRAME(7);
	HIDE_HUD_COMPONENT_THIS_FRAME(8);
	HIDE_HUD_COMPONENT_THIS_FRAME(9);
	SET_INPUT_EXCLUSIVE(0, 166);
	SET_INPUT_EXCLUSIVE(0, 167);
	SET_INPUT_EXCLUSIVE(0, 177);
	SET_INPUT_EXCLUSIVE(0, 178);
	SET_INPUT_EXCLUSIVE(0, 179);
	SET_INPUT_EXCLUSIVE(0, 202);
	SET_INPUT_EXCLUSIVE(0, 203);
}

RGB GetSpriteColour(bool On)
{
	if (!(On == false))
	{
		return RGB(SpriteOnR, SpriteOnG, SpriteOnB);
	}
	else
	{
		return RGB(SpriteOffR, SpriteOffG, SpriteOffB);
	}
}

RGB GetOptionColour()
{
	if (CurrentOption == OptionCount)
	{
		return RGB(SelectedTextR, SelectedTextG, SelectedTextB);
	}
	else
	{
		return RGB(UnselectedTextR, UnselectedTextG, UnselectedTextB);
	}
}

void AddOption(const char* OptionText)
{
	OptionCoordStartingPoint = 0.0f;
	RGB optionColour;
	OptionCount++;
	if ((CurrentOption < 7) || (SubmenuOptionCount <= 13))
	{
		if (!(OptionCount > 13))
		{
		    OptionCoordStartingPoint = OptionCount;
		}
	}
	else if ((SubmenuOptionCount - CurrentOption) < 6)
	{
		if (!(OptionCount <= (SubmenuOptionCount - 13)))
		{
			OptionCoordStartingPoint = OptionCount - (SubmenuOptionCount - 13);
		}
	}
	else if (!((OptionCount < (CurrentOption - 6)) || (OptionCount > (CurrentOption + 6))))
	{
		OptionCoordStartingPoint = OptionCount - (CurrentOption - 7);
	}
	if (!(OptionCoordStartingPoint == 0.0f))
	{
		OptionCoord = (OptionCoordStartingPoint * 0.035f) + (0.5791f - GetSafezoneSizeHalfed());
		// OptionCoord = (OptionCoordStartingPoint * 0.035f) + (0.5691f - GetSafezoneSizeHalfed());
		optionColour = GetOptionColour();
		StringBase(OptionFont, optionColour.r, optionColour.g, optionColour.b, TextOutlineOptions);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(OptionText);
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2(MenuXCoord1, OptionCoord));
	}
}





void AddOpacityButtonSB00(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 0;
	}
}
void AddOpacityButtonSB10(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 25;
	}
}
void AddOpacityButtonSB20(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 51;
	}
}
void AddOpacityButtonSB30(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 76;
	}
}
void AddOpacityButtonSB40(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 102;
	}
}
void AddOpacityButtonSB50(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 127;
	}
}
void AddOpacityButtonSB60(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 153;
	}
}
void AddOpacityButtonSB70(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 178;
	}
}
void AddOpacityButtonSB80(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 204;
	}
}
void AddOpacityButtonSB90(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 229;
	}
}
void AddOpacityButtonSB100(const char* OptionText)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		ScrollbarA = 255;
	}
}









void AddSettingsBgChanger(const char* OptionText, char* BackgroundDDSname, char* BackgroundCTDname)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		
		Background_Name = BackgroundDDSname;
		Background_File = BackgroundCTDname;

	}
}

void AddOpacityButtonBG00(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 255;
	}
}
void AddOpacityButtonBG10(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 229;
	}
}
void AddOpacityButtonBG20(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 204;
	}
}
void AddOpacityButtonBG30(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 178;
	}
}
void AddOpacityButtonBG40(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 153;
	}
}
void AddOpacityButtonBG50(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 127;
	}
}
void AddOpacityButtonBG60(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 102;
	}
}
void AddOpacityButtonBG70(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 76;
	}
}
void AddOpacityButtonBG80(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 51;
	}
}
void AddOpacityButtonBG90(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 25;
	}
}
void AddOpacityButtonBG100(const char* OptionText) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		BackgroundA = 0;
	}
}

void AddColorBanner01(const char* OptionText, int colorBannerSet, int colorSetR, int colorSetG, int colorSetB, int NCV1LogoSet) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		if (colorBannerSet == false) {
			BannerR = colorSetR;
			BannerG = colorSetG;
			BannerB = colorSetB;
			TitleR = 0;
			TitleG = 0;
			TitleB = 0;
			TitleRmain = 0;
			TitleGmain = 0;
			TitleBmain = 0;
			TitleAmain = 255;
			ScrollArrowsR = 0;
			ScrollArrowsG = 0;
			ScrollArrowsB = 0;
		} else if (colorBannerSet == true) {
			BannerR = colorSetR;
			BannerG = colorSetG;
			BannerB = colorSetB;
			TitleR = 255;
			TitleG = 255;
			TitleB = 255;
			TitleRmain = 255;
			TitleGmain = 255;
			TitleBmain = 255;
			TitleAmain = 255;
			ScrollArrowsR = 255;
			ScrollArrowsG = 255;
			ScrollArrowsB = 255;
		}
		if (NCV1LogoSet == false) {
			Enable_Title = false;
		} else if (NCV1LogoSet == true) {
			Enable_Title = true;
		}
	}
}

void AddColorScrollbar01(const char* OptionText, int colorScrollbar, int colorSetRb, int colorSetGb, int colorSetBb) {
	AddOption(OptionText);
	if (WasXJustPressed()) {
		if (colorScrollbar == false) {
			ScrollbarR = colorSetRb;
			ScrollbarG = colorSetGb;
			ScrollbarB = colorSetBb;
			SelectedTextR = 0;
			SelectedTextG = 0;
			SelectedTextB = 0;
		} else if (colorScrollbar == true) {
			ScrollbarR = colorSetRb;
			ScrollbarG = colorSetGb;
			ScrollbarB = colorSetBb;
			SelectedTextR = 255;
			SelectedTextG = 255;
			SelectedTextB = 255;
		}
	}
}


// FOR CHECK BOX [testa]

// void OptionStatus(int status)
// {
// 	if (!HAS_STREAMED_TEXTURE_DICT_LOADED("Commonmenu"))
// 	{
// 		REQUEST_STREAMED_TEXTURE_DICT("Commonmenu", 0);
// 	}	
// 	if (status == 0)	
// 	{		
// 		DRAW_SPRITE("Commonmenu", "shop_box_blank", 0.25 + CurrentMenuPos, Option_Y + 0.0128, 0.033, 0.043, 0.0, 255, 255, 255, 255);	
// 	}	
// 	else if (status == 1)	
// 	{		
// 		DRAW_SPRITE("Commonmenu", "shop_box_tick", 0.25 + CurrentMenuPos, Option_Y + 0.0128, 0.033, 0.043, 0.0, 255, 255, 255, 255);	
// 	}
// 	if (menu::printingoption == menu::currentoption && status == 0)	
// 	{		
// 		DRAW_SPRITE("Commonmenu", "shop_box_blankb", 0.25 + CurrentMenuPos, Option_Y + 0.0128, 0.033, 0.043, 0.0, 255, 255, 255, 255);
// 	}
// 	else if (menu::printingoption == menu::currentoption && status == 1)
// 	{	
// 		DRAW_SPRITE("Commonmenu", "shop_box_tickb", 0.25 + CurrentMenuPos, Option_Y + 0.0128, 0.033, 0.043, 0.0, 255, 255, 255, 255);	
// 	}
// }

// OptionStatus(static_cast<int>(loopVariable));










void AddOnOffOption(bool On)
{
	float SpriteCoordStartingPoint = 0.0f;
	RGB spriteColour;
    if ((CurrentOption < 7) || (SubmenuOptionCount <= 13))
	{
		if (!(OptionCount > 13))
		{
		    SpriteCoordStartingPoint = OptionCount;
		}
	}
	else if ((SubmenuOptionCount - CurrentOption) < 6)
	{
		if (!(OptionCount <= (SubmenuOptionCount - 13)))
		{
			SpriteCoordStartingPoint = OptionCount - (SubmenuOptionCount - 13);
		}
	}
	else if (!((OptionCount < (CurrentOption - 6)) || (OptionCount > (CurrentOption + 6))))
	{
		SpriteCoordStartingPoint = OptionCount - (CurrentOption - 7);
	}
	if (!(SpriteCoordStartingPoint == 0.0f))
	{
		SpriteCoord = (SpriteCoordStartingPoint * 0.035f) + (0.5971f - GetSafezoneSizeHalfed());
		// SpriteCoord = (SpriteCoordStartingPoint * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
	    MaybeLoadTexture("commonmenu");
	    if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
		{
			if (!(SpriteOutline == false))
			{
				DRAW_SPRITE("commonmenu", "common_medal", vector2((MenuXCoord2 - 0.006f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
			}
			spriteColour = GetSpriteColour(On);
			DRAW_SPRITE("commonmenu", "common_medal", vector2((MenuXCoord2 - 0.006f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(spriteColour.r, spriteColour.g, spriteColour.b, 255));
		}
	}
}

void AddGlareDrawedOption(const char* Optiontext) {
	AddOption(Optiontext);

	if (WasXJustPressed()) {
		AddOnOffOption(true);
		if (GlareToggle == false) {
			GlareToggle = true;
		} else if (GlareToggle == true) {
			GlareToggle = false;
		}
	} else {
		AddOnOffOption(false);
	}

}

void AddLeftSidedOption(const char* Optiontext) {
	AddOption(Optiontext);

	if (WasXJustPressed()) {
		AddOnOffOption(true);
		if (LeftSided == false) {
			LeftSided = true;
		} else if (LeftSided == true) {
			LeftSided = false;
		}
	} else {
		AddOnOffOption(false);
	}

}

void GetTextWrap()
{
	if (CurrentOption == OptionCount)
	{
		SET_TEXT_WRAP(0.0f, (MenuXCoord2 - 0.0324f));
	}
	else
	{
		SET_TEXT_WRAP(0.0f, (MenuXCoord2 - 0.0159f));
	}
}

int GetStackSizeFromValue(int value)
{
	int StackSize;
	switch(value)
	{
		case 0: {StackSize = 128; break;}
		case 1: {StackSize = 512; break;}
		case 2: {StackSize = 1024; break;}
		case 3: {StackSize = 1820; break;}
		case 4: {StackSize = 1828; break;}
		case 5: {StackSize = 2024; break;}
		case 6: {StackSize = 2552; break;}
		case 7: {StackSize = 2556; break;}
		case 8: {StackSize = 2800; break;}
		case 9: {StackSize = 3076; break;}
		case 10: {StackSize = 3150; break;}
		case 11: {StackSize = 3584; break;}
		case 12: {StackSize = 4592; break;}
		case 13: {StackSize = 4600; break;}
		case 14: {StackSize = 5000; break;}
		case 15: {StackSize = 6304; break;}
		case 16: {StackSize = 8032; break;}
		case 17: {StackSize = 9300; break;}
		case 18: {StackSize = 15000; break;}
		case 19: {StackSize = 21000; break;}
	}
	return StackSize;
}

void AddLeftRightOption()
{
	MaybeLoadTexture("commonmenu");
	if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
	{
		DRAW_SPRITE("commonmenu", "shop_arrows_upanddown", vector2((MenuXCoord2 - 0.0235f), ScrollArrowsCoord), Size(0.025f, 0.0444f), 90.0f, RGBA(SelectedTextR, SelectedTextG, SelectedTextB, 255));
	}
}

void AddIntOption(int* DisplayNumber, int minValue, int maxValue)
{
	RGB optionColour;
	if (CurrentOption == OptionCount)
	{
		AddLeftRightOption();
		if (IsControlPressed(166))
		{
			PlayMenuSound("NAV_LEFT_RIGHT");
			if (*DisplayNumber == minValue)
			{
				*DisplayNumber = maxValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber - 1;
			}
		}
		else if (IsControlPressed(167))
		{
			PlayMenuSound("NAV_LEFT_RIGHT");
			if (*DisplayNumber == maxValue)
			{
				*DisplayNumber = minValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber + 1;
			}
		}
	}
	if (!(OptionCoordStartingPoint == 0.0f))
	{
		optionColour = GetOptionColour();
		StringBase(OptionFont, optionColour.r, optionColour.g, optionColour.b, TextOutlineOptions);
		GetTextWrap();
		SET_TEXT_RIGHT_JUSTIFY(true);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
		ADD_TEXT_COMPONENT_INTEGER(GetStackSizeFromValue(*DisplayNumber));
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2(0.0f, OptionCoord));
	}
}

void DrawMenuOpeningBinds(int Button1, int Button2)
{
	float SpriteCoordStartingPoint = 0.0f;
    if ((CurrentOption < 7) || (SubmenuOptionCount <= 13))
	{
		if (!(OptionCount > 13))
		{
		    SpriteCoordStartingPoint = OptionCount;
		}
	}
	else if ((SubmenuOptionCount - CurrentOption) < 6)
	{
		if (!(OptionCount <= (SubmenuOptionCount - 13)))
		{
			SpriteCoordStartingPoint = OptionCount - (SubmenuOptionCount - 13);
		}
	}
	else if (!((OptionCount < (CurrentOption - 6)) || (OptionCount > (CurrentOption + 6))))
	{
		SpriteCoordStartingPoint = OptionCount - (CurrentOption - 7);
	}
	if (!(SpriteCoordStartingPoint == 0.0f))
	{
		SpriteCoord = (SpriteCoordStartingPoint * 0.035f) + (0.5971f - GetSafezoneSizeHalfed());
		// SpriteCoord = (SpriteCoordStartingPoint * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
	    MaybeLoadTexture("erootiik");
	    if (HAS_STREAMED_TEXTURE_DICT_LOADED("erootiik"))
		{
			if (!(Button1 == 0))
			{
				DRAW_SPRITE("erootiik", straddiGlobal("button_", Button1), vector2((MenuXCoord2 - 0.066f), SpriteCoord), Size(0.016f, 0.0289f), 0.0f, RGBA(255, 255, 255, 255));
				if (!(Button2 == 0))
				{
					StringBase(OptionFont, 255, 255, 255, true);
					BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
					ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("+");
					END_TEXT_COMMAND_DISPLAY_TEXT(vector2((MenuXCoord2 - 0.0555f), OptionCoord));
				}
		    }
			if (!(Button2 == 0))
			{
				DRAW_SPRITE("erootiik", straddiGlobal("button_", Button2), vector2((MenuXCoord2 - 0.036f), SpriteCoord), Size(0.016f, 0.0289f), 0.0f, RGBA(255, 255, 255, 255));
			}
		}
	}
}	
	
void AddScriptOption(const char* OptionText, char* ScriptName, int StackSize, int Button1, int Button2)
{
	char* ErrorMessage;
	if (!DOES_SCRIPT_EXIST(ScriptName))
	{
		if (IS_PS3_VERSION())
		{
			ErrorMessage = "Please report the error";
			// ErrorMessage = ".csc Not Found!";
		}
		else 
		{
			ErrorMessage = "Please report the error";
			// ErrorMessage = ".xex Not Found!";
		}
		AddOption(strcatGlobal(ScriptName, ErrorMessage));
	}
	else
	{
		AddOption(OptionText);
		DrawMenuOpeningBinds(Button1, Button2);
		AddOnOffOption(_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)));
		if (WasXJustPressed())
		{
			if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)) == 0)
			{
				ScriptToLoad = ScriptName;
				ScriptToLoadStackSize = StackSize;
			}
			else
			{
				TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(ScriptName);
			}
		}
	}
}

void AddInstructionalButton(int Button, const char* Text)
{
	if (!AlreadySetup)
	{
		InstructionalButtonCount = -1;
		InstructionalButtonsHandle = REQUEST_SCALEFORM_MOVIE("INSTRUCTIONAL_BUTTONS");
		if (HAS_SCALEFORM_MOVIE_LOADED(InstructionalButtonsHandle))
		{
			DRAW_SCALEFORM_MOVIE_FULLSCREEN(InstructionalButtonsHandle, RGBA(255, 255, 255, 255), 0);
			_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "CLEAR_ALL");
			_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "SET_CLEAR_SPACE");
			_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(200);
			_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			AlreadySetup = true;
		}
	}
	if (HAS_SCALEFORM_MOVIE_LOADED(InstructionalButtonsHandle))
	{
		InstructionalButtonCount++;
		_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "SET_DATA_SLOT");
		_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(InstructionalButtonCount);
		_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(Button);
		BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Text);
		END_TEXT_COMMAND_SCALEFORM_STRING();
		_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	}
}

void DrawInstructionalButtons()
{
	_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "DRAW_INSTRUCTIONAL_BUTTONS");
	_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "SET_BACKGROUND_COLOUR");
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(80);
	_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	AlreadySetup = false;
}
	
void AddScriptOptionNoBinds(char* ScriptName, int* StackSize)
{
	if(!(IS_STRING_NULL_OR_EMPTY(ScriptName)))
	{
		AddOption(ScriptName);
		if (CurrentOption == OptionCount)
		{
			AddInstructionalButton(32, "Remove");
			if (IS_DISABLED_CONTROL_JUST_PRESSED(0, 179))
			{
				strcpy(ScriptName, "", 30);
				*StackSize = 0;
				CustomScriptCount--;
				if (!(CurrentOption == 1))
				{
					CurrentOption--;
				}
			}
		}
		if (DOES_SCRIPT_EXIST(ScriptName))
		{
			AddOnOffOption(_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)));
			AddIntOption(StackSize, 0, 19);
			if (WasXJustPressed())
		    {
			    if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)) == 0)
			    {
				    ScriptToLoad = ScriptName;
				    ScriptToLoadStackSize = GetStackSizeFromValue(*StackSize);
			    }
			    else
			    {
				    TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(ScriptName);
			    }
		    }
		}
	}
}

void AddSubmenuOption(const char* OptionText, void* submenuLoc)
{
	AddOption(OptionText);
	if (WasXJustPressed())
	{
		LastSubmenu[SubmenuLevel] = CurrentSubmenu;
		LastOption[SubmenuLevel] = CurrentOption;
		CurrentSubmenu = submenuLoc;
		CurrentOption = 1;
		SubmenuLevel++;
	}
}

void AddSubmenuOption2(const char* OptionText, void* submenuLoc)
{
	AddOption(OptionText);
	if (WasXJustPressed()) {
		LastSubmenu[SubmenuLevel] = CurrentSubmenu;
		LastOption[SubmenuLevel] = CurrentOption;
		CurrentSubmenu = submenuLoc;
		CurrentOption = 1;
		SubmenuLevel++;
	}

}


void AddCustomScriptOption()
{
	AddOption("Add Your Script");
	if (WasXJustPressed())
	{
		DISPLAY_ONSCREEN_KEYBOARD(0, "", "", "", "", "", "", 31);
		KeyboardMonitoring = true;
	}
}

void SetKeyboardResultIntoOption(const char* ScriptName)
{
	if (IS_STRING_NULL_OR_EMPTY(CustomScript1))
	{
		strcpy(CustomScript1, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript2))
	{
		strcpy(CustomScript2, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript3))
	{
		strcpy(CustomScript3, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript4))
	{
		strcpy(CustomScript4, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript5))
	{
		strcpy(CustomScript5, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript6))
	{
		strcpy(CustomScript6, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript7))
	{
		strcpy(CustomScript7, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript8))
	{
		strcpy(CustomScript8, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript9))
	{
		strcpy(CustomScript9, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript10))
	{
		strcpy(CustomScript10, ScriptName, 30);
	}
}
	
void UpdateCustomScriptCount()
{
	if (!(CustomScriptCount == 10))
	{
		CustomScriptCount++;
	}
}

void UpdateCurrentOption()
{
	if (!(CustomScriptCount == 10))
	{
		CurrentOption++;
	}
}
