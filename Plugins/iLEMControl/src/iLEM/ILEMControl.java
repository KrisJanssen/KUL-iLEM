/**
 * StageControl plugin
 *
 * This Micro-Manager plugin provides a simple interface to the currently active
 * XY stage and Z (focus) drive
 *
 * Created on Aug 19, 2010, 10:04:49 PM Nico Stuurman, copyright UCSF, 2010
 *
 * LICENSE: This file is distributed under the BSD license. License text is
 * included with the source distribution.
 *
 * This file is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.
 *
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES.
 *
 */
package iLEM;

import mmcorej.CMMCore;
import org.micromanager.api.MMPlugin;
import org.micromanager.api.ScriptInterface;
import static iLEM.ILEMControl.tooltipDescription;
import javax.swing.WindowConstants;

public class ILEMControl implements MMPlugin {

    public static String menuName = "FluoSEM Control";
    public static String tooltipDescription = "FluoSEM Control.";
    private CMMCore core_;
    private CMMCore mmc;
    private ScriptInterface gui_;
    private ScriptInterface gui;
    private ILEMControlFrame myFrame_;

    public void setApp(ScriptInterface app) {
        gui_ = app;
        gui = gui_;
        core_ = app.getMMCore();
        mmc = core_;
        if (myFrame_ == null) {
            myFrame_ = new ILEMControlFrame(gui_);
        }
        myFrame_.setVisible(true);
        myFrame_.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    }

    public void dispose() {
        // nothing todo:
    }

    public void show() {
        String ig = "FluoSEM Control";
    }

    public void configurationChanged() {
    }

    public String getInfo() {
        return "FluoSEM Control Plugin";
    }

    public String getDescription() {
        return tooltipDescription;
    }

    public String getVersion() {
        return "First version";
    }

    public String getCopyright() {
        return "KU Leuven, 2014";
    }
}
