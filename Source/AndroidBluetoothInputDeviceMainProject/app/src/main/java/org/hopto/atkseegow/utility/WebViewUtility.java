package org.hopto.atkseegow.utility;

import android.app.Activity;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import org.hopto.atkseegow.bluetoothinputdevice.R;
import org.hopto.atkseegow.domain.Config;

public class WebViewUtility {
    public static void Initialization(Activity activity){
        String descriptionURL = Config.DescriptionURL;
        WebView descriptionBrowser = (WebView)activity.findViewById(R.id.descriptionBrowser);

        WebSettings websettings = descriptionBrowser.getSettings();
        websettings.setSupportZoom(true);
        websettings.setBuiltInZoomControls(true);
        websettings.setJavaScriptEnabled(true);

        descriptionBrowser.setWebViewClient(new WebViewClient());
        descriptionBrowser.loadUrl(descriptionURL);
    }
}
