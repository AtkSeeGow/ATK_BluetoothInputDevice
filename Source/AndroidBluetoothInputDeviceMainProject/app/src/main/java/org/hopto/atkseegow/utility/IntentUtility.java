package org.hopto.atkseegow.utility;

import android.app.Activity;
import android.content.Intent;

public class IntentUtility {
    public static void RedirectTo(Activity currentActivity, Class targetActivity, boolean isFinish){
        Intent intent = new Intent();
        intent.setClass(currentActivity, targetActivity);
        currentActivity.startActivity(intent);
        if(isFinish)
            currentActivity.finish();
    }
}