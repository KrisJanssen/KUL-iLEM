/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package iLEM;

import bsh.EvalError;
import bsh.Interpreter;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileReader;
import java.io.IOException;
import java.text.NumberFormat;
import java.util.prefs.Preferences;
import javax.swing.Timer;
import mmcorej.CMMCore;
import mmcorej.StrVector;
import org.micromanager.api.ScriptInterface;

/**
 *
 * @author Kris Janssen. Based on early code by Thomas Franklin.
 */
public class ILEMControlFrame extends javax.swing.JFrame {

    /**
     * Creates new form FluoSEMControl
     */
    //Objects to hold interface with micromanager
    private final ScriptInterface gui_;
    private final CMMCore core_;
    
    //Beansell intepreter for running scripts
    Interpreter bsh = new Interpreter();  

    //Labels for many of the devices
    private static String nm405Label = "Laser 405nm";
    private static String nm445Label = "Laser 445nm";
    private static String nm488Label = "Laser 488nm";
    private static String nm532Label = "Laser 532nm";
    private static String nm561Label = "Laser 561nm";
    private static String nm642Label = "Laser 642nm";

    private static String nm405ENLabel = "Laser 405nmEN";
    private static String nm445ENLabel = "Laser 445nmEN";
    private static String nm488ENLabel = "Laser 488nmEN";
    private static String nm532ENLabel = "Laser 532nmEN";
    private static String nm561ENLabel = "Laser 561nmEN";
    private static String nm642ENLabel = "Laser 642nmEN";

    private static String nm365PLabel = "Diode 365nmP";
    private static String nm405PLabel = "Laser 405nmP";
    private static String nm445PLabel = "Laser 445nmP";
    private static String nm488PLabel = "Laser 488nmP";
    private static String nm532PLabel = "Laser 532nmP";
    private static String nm561PLabel = "Laser 561nmP";
    private static String nm642PLabel = "Laser 642nmP";

    
    //Preferences and storage of variables
    
    private Preferences prefs_;

    private double smallMovement_ = 1.0;
    private double mediumMovement_ = 10.0;
    private double largeMovement_ = 100.0;
    private double smallMovementZ_ = 1.0;
    private double mediumMovementZ_ = 10.0;
    private double smallMovementLR_ = 1.0;
    private double mediumMovementLR_ = 10.0;

    private NumberFormat nf_;

    private int frameXPos_ = 100;
    private int frameYPos_ = 100;

    private static final String FRAMEXPOS = "FRAMEXPOS";
    private static final String FRAMEYPOS = "FRAMEYPOS";
    private static final String SMALLMOVEMENT = "SMALLMOVEMENT";
    private static final String MEDIUMMOVEMENT = "MEDIUMMOVEMENT";
    private static final String LARGEMOVEMENT = "LARGEMOVEMENT";
    private static final String SMALLMOVEMENTZ = "SMALLMOVEMENTZ";
    private static final String MEDIUMMOVEMENTZ = "MEDIUMMOVEMENTZ";

    private static String SampleXYLabel = "SECOM-Sample-XY";
    private static String ObjectiveZLabel = "SECOM-Objective-Z";
    private static String ObjectiveXYLabel = "SECOM-Objective-XY";

    //Declare timers for polling/timeouts
    private static Timer positionTimer;
    private static Timer laserOnTimer;
    private static Timer SEMTimer;

    private double Xpos, Ypos, Zpos;

    //Set state of system to nothing loaded
    private boolean isCameraLoaded, isXYStageLoaded, isLRStageLoaded, isZStageLoaded, isLaserLoaded, isSEMLoaded = false;

    //Enable the LC Filter tab.
    private void LCFilterEnable(boolean enabled)
    {
        jTabbedPane1.setEnabledAt(3, enabled);
    }
    
    //Enable the laser tab, Set up the laser powers and make sure everything is switched off...
    private void LaserEnable(boolean enabled) {
        if (isLaserLoaded == true) {
            LaserToggle.setEnabled(enabled);
            jTabbedPane1.setEnabledAt(1, enabled);

            try {
                core_.setProperty(nm405Label, "Laser Power Set-point Select [mW]", "120.0");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm445Label, "Laser Power Set-point Select [mW]", "100.0");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm488Label, "Laser Power Set-point Select [mW]", "200.0");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm642Label, "Laser Power Set-point Select [mW]", "140.0");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm532Label, "Power", 0.3);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm561Label, "Power", 0.15);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm365PLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm405ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm405PLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm445ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm445PLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm488ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm488PLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm532ENLabel, "Volts", 5.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm532PLabel, "Volts", 5.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm561ENLabel, "Volts", 5.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm561PLabel, "Volts", 5.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm642ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm642PLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            
            //These set the initial state displayed in the GUI to off
            State365.setText("OFF");
            State405.setText("OFF");
            State445.setText("OFF");
            State488.setText("OFF");
            State532.setText("OFF");
            State561.setText("OFF");
            State642.setText("OFF");
            
            //This is the timer for the laser protection. This runs every second...
            ActionListener LaserProtection = new ActionListener() {
                public void actionPerformed(ActionEvent d) {
                    

                    boolean conflict = false;
                    String nm365 = "";
                    String nm405 = "";
                    String nm445 = "";
                    String nm488 = "";
                    String nm532 = "";
                    String nm561 = "";
                    String nm642 = "";

                    try {
                        nm532 = core_.getPropertyFromCache(nm532Label, "Laser");
                        nm561 = core_.getPropertyFromCache(nm561Label, "Laser");
                        nm365 = core_.getPropertyFromCache(nm365PLabel, "Volts");
                        nm405 = core_.getPropertyFromCache(nm405ENLabel, "Volts");
                        nm445 = core_.getPropertyFromCache(nm445ENLabel, "Volts");
                        nm488 = core_.getPropertyFromCache(nm488ENLabel, "Volts");
                        nm642 = core_.getPropertyFromCache(nm642ENLabel, "Volts");
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    if (Float.parseFloat(nm365) > 0) {
                        State365.setText("ON");
                        State365.setBackground(Color.red);
                        if (!LaserToggle.isSelected()) {
                            try {
                                core_.setProperty(nm365PLabel, "Volts", 0.0);
                            } catch (Exception e) {
                                gui_.logError(e);
                            }
                            conflict = true;
                        }
                    } else if (Laser365OnOff.isSelected()) {
                        State365.setText("READY");
                        State365.setBackground(Color.yellow);
                    } else {
                        State365.setText("OFF");
                        State365.setBackground(Color.green);
                    }
                    if (Float.parseFloat(nm405) > 0) {
                        State405.setText("ON");
                        State405.setBackground(Color.red);
                        if (!LaserToggle.isSelected()) {
                            try {
                                core_.setProperty(nm405ENLabel, "Volts", 0.0);
                            } catch (Exception e) {
                                gui_.logError(e);
                            }
                            conflict = true;
                        }
                    } else if (Laser405OnOff.isSelected()) {
                        State405.setText("READY");
                        State405.setBackground(Color.yellow);
                    } else {
                        State405.setText("OFF");
                        State405.setBackground(Color.green);
                    }

                    if (Float.parseFloat(nm445) > 0) {
                        State445.setText("ON");
                        State445.setBackground(Color.red);
                        if (!LaserToggle.isSelected()) {
                            try {
                                core_.setProperty(nm445ENLabel, "Volts", 0.0);
                            } catch (Exception e) {
                                gui_.logError(e);
                            }
                            conflict = true;
                        }
                    } else if (Laser445OnOff.isSelected()) {
                        State445.setText("READY");
                        State445.setBackground(Color.yellow);
                    } else {
                        State445.setText("OFF");
                        State445.setBackground(Color.green);
                    }

                    if (Float.parseFloat(nm488) > 0) {
                        State488.setText("ON");
                        State488.setBackground(Color.red);
                        if (!LaserToggle.isSelected()) {
                            try {
                                core_.setProperty(nm488ENLabel, "Volts", 0.0);
                            } catch (Exception e) {
                                gui_.logError(e);
                            }
                            conflict = true;
                        }
                    } else if (Laser488OnOff.isSelected()) {
                        State488.setText("READY");
                        State488.setBackground(Color.yellow);
                    } else {
                        State488.setText("OFF");
                        State488.setBackground(Color.green);
                    }

                    if (Float.parseFloat(nm642) > 0) {
                        if (!LaserToggle.isSelected()) {
                            State642.setText("ON");
                            State642.setBackground(Color.red);
                            try {
                                core_.setProperty(nm642Label, "Laser Operation Select", "Off");
                                core_.setProperty(nm642ENLabel, "Volts", 0.0);
                            } catch (Exception e) {
                                gui_.logError(e);
                            }
                            conflict = true;
                        }
                    } else if (Laser642OnOff.isSelected()) {
                        State642.setText("READY");
                        State642.setBackground(Color.yellow);
                    } else {
                        State642.setText("OFF");
                        State642.setBackground(Color.green);
                    }
                    if (nm532.startsWith("On")) {
                        State532.setText("ON");
                        State532.setBackground(Color.red);
                        if (!LaserToggle.isSelected()) {
                            try {
                                core_.setProperty(nm532Label, "Laser", "Off");
                            } catch (Exception e) {
                                gui_.logError(e);
                            }
                            conflict = true;
                        }
                    } else if (Laser532OnOff.isSelected()) {
                        State532.setText("READY");
                        State532.setBackground(Color.yellow);
                    } else {
                        State532.setText("OFF");
                        State532.setBackground(Color.green);
                    }
                    if (nm561.startsWith("On")) {
                        State561.setText("ON");
                        State561.setBackground(Color.red);
                        if (!LaserToggle.isSelected()) {
                            try {
                                core_.setProperty(nm561Label, "Laser", "Off");
                            } catch (Exception e) {
                                gui_.logError(e);
                            }
                            conflict = true;
                        }
                    } else if (Laser561OnOff.isSelected()) {
                        State561.setText("READY");
                        State561.setBackground(Color.yellow);
                    } else {
                        State561.setText("OFF");
                        State561.setBackground(Color.green);
                    }
                    if (conflict == true) {
                        LaserToggle.setText("OFF:CONFLICT");
                    }
                    try {
                        jPower1.setText(core_.getProperty(nm405Label, "Laser Power Status [mW]"));
                        Power405.setText(jPower1.getText());
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    try {
                        jPower2.setText(core_.getProperty(nm445Label, "Laser Power Status [mW]"));
                        Power445.setText(jPower2.getText());
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    try {
                        jPower3.setText(core_.getProperty(nm488Label, "Laser Power Status [mW]"));
                        Power488.setText(jPower3.getText());
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    try {
                        jPower12.setText(core_.getProperty(nm642Label, "Laser Power Status [mW]"));
                        Power642.setText(jPower12.getText());
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    try {
                        Power365.setText((float) 3 / (float) 5 * Float.parseFloat(core_.getPropertyFromCache(nm365PLabel, "Volts")) + " mW (E)");
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    try {
                        Power532.setText((float) 300 / (float) 5 * (5.0 - Float.parseFloat(core_.getPropertyFromCache(nm532ENLabel, "Volts"))) + " mW (E)");
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    try {
                        Power561.setText((float) 150 / (float) 5 * (5.0 - Float.parseFloat(core_.getPropertyFromCache(nm561ENLabel, "Volts"))) + " mW (E)");
                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                }
            };
            laserOnTimer = new Timer(1000, LaserProtection);
            laserOnTimer.start();

        } else {
            
            if (laserOnTimer.isRunning()) {
                laserOnTimer.stop();
            }
        }
    }

    private void XYStageEnable(boolean enabled) {
        if (isXYStageLoaded == true) {
            XYSmallLeft.setEnabled(enabled);
            XYBigLeft.setEnabled(enabled);
            XYMedLeft.setEnabled(enabled);
            XYSmallRight.setEnabled(enabled);
            XYBigRight.setEnabled(enabled);
            XYMedRight.setEnabled(enabled);
            XYSmallUp.setEnabled(enabled);
            XYBigUp.setEnabled(enabled);
            XYMedUp.setEnabled(enabled);
            XYSmallDown.setEnabled(enabled);
            XYMedDown.setEnabled(enabled);
            XYBigDown.setEnabled(enabled);
            ActionListener uiUpdateListener;
            uiUpdateListener = new ActionListener() {
                public void actionPerformed(ActionEvent d) {
                    // 1 Sekunde abziehen
                    try {

                        Xpos = core_.getXPosition(SampleXYLabel);
                        Ypos = core_.getYPosition(SampleXYLabel);
                        Zpos = core_.getPosition(ObjectiveZLabel);

                    } catch (Exception e) {
                        gui_.logError(e);
                    }
                    XPositionLabel.setText(String.format("%.3f", Xpos));
                    YPositionLabel.setText(String.format("%.3f", Ypos));
                    ZPositionLabel.setText(String.format("%.3f", Zpos));
                }
            };

            positionTimer = new Timer(500, uiUpdateListener);
            positionTimer.start();

            if ((isXYStageLoaded == true) || (isZStageLoaded == true)) {
                jTabbedPane1.setEnabledAt(0, true);
            } else {
                jTabbedPane1.setEnabledAt(0, false);
                if (positionTimer.isRunning()) {
                    positionTimer.stop();
                }
            }
        }

    }

    private void ZStageEnable(boolean enabled) {
        if (isZStageLoaded == true) {
            ZBigUp.setEnabled(enabled);
            ZSmallUp.setEnabled(enabled);
            ZSmallDown.setEnabled(enabled);
            ZBigDown.setEnabled(enabled);
            ZDownSlider.setEnabled(enabled);
            ZUpSlider.setEnabled(enabled);
            ZFineSlider.setEnabled(enabled);
            if ((isXYStageLoaded == true) || (isZStageLoaded == true)) {
                jTabbedPane1.setEnabledAt(0, true);
            } else {
                jTabbedPane1.setEnabledAt(0, false);
            }
        }

    }

    private void LRStageEnable(boolean enabled) {
        if (isLRStageLoaded == true) {

            LRSmallLeft.setEnabled(enabled);
            LRSmallDown.setEnabled(enabled);
            LRBigLeft.setEnabled(enabled);
            LRSmallUp.setEnabled(enabled);
            LRBigDown.setEnabled(enabled);
            LRSmallRight.setEnabled(enabled);
            LRBigUp.setEnabled(enabled);
            CalibrateLR.setEnabled(enabled);
            CrudeAutoAlignment.setEnabled(enabled);
            LRBigRight.setEnabled(enabled);
        }

    }

    private void CameraEnable(boolean enabled) {
        if (isCameraLoaded == true) {
            EMGain.setEnabled(enabled);
            // Exposure.setEnabled(enabled);
            //Binning.setEnabled(enabled);
            ToggleShutter.setEnabled(enabled);

        }

    }

    private void SEMEnable(boolean enabled) {
        if (isSEMLoaded == true) {
            String SEMFOV;
            ActionListener taskPerformer3;
            taskPerformer3 = new ActionListener() {
                public void actionPerformed(ActionEvent d) {
                    // 1 Sekunde abziehen
                    try {

                        SEMHFW.setText(Double.toString(Double.parseDouble(core_.getProperty("FEISEM-MT", "FOV X (um)"))));

                    } catch (Exception e) {
                        gui_.logError(e);
                    }

                }
            };

            SEMTimer = new Timer(1000, taskPerformer3);
            SEMTimer.start();
        }

    }

    private void updateMovementFields() {
        smallMovement_ = Double.parseDouble(jTextField1.getText());
        mediumMovement_ = Double.parseDouble(jTextField2.getText());
        largeMovement_ = Double.parseDouble(jTextField3.getText());
        smallMovementZ_ = Double.parseDouble(ZSmallStepsSet.getText());
        mediumMovementZ_ = Double.parseDouble(ZBigStepsSet.getText());
        smallMovementLR_ = Double.parseDouble(LRSmallStepsSet.getText());
        mediumMovementLR_ = Double.parseDouble(LRLargeStepsSet.getText());
    }

    private void ResetStages() {
        if (isXYStageLoaded) {
            try {
                core_.setProperty(SampleXYLabel, "Reset?", 1);
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
        if (isLRStageLoaded) {
            try {
                core_.setProperty(ObjectiveXYLabel, "Reset?", 1);
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
        if (isZStageLoaded) {
            try {
                core_.setProperty(ObjectiveZLabel, "Reset?", 1);
            } catch (Exception e) {
                gui_.logError(e);
            }
        }

    }

    public ILEMControlFrame(ScriptInterface gui) {

        gui_ = gui;
        core_ = gui_.getMMCore();
        nf_ = NumberFormat.getInstance();
        prefs_ = Preferences.userNodeForPackage(this.getClass());

        // Read values from PREFS
        frameXPos_ = prefs_.getInt(FRAMEXPOS, frameXPos_);
        frameYPos_ = prefs_.getInt(FRAMEYPOS, frameYPos_);
        initComponents();
        setLocation(0, 0);

        jTabbedPane1.setEnabledAt(3, false);
        jTabbedPane1.setEnabledAt(4, false);

        setBackground(gui_.getBackgroundColor());
        gui_.addMMBackgroundListener(this);

        jTextField1.setText(nf_.format(smallMovement_));
        jTextField2.setText(nf_.format(mediumMovement_));
        jTextField3.setText(nf_.format(largeMovement_));
        ZSmallStepsSet.setText(nf_.format(smallMovementZ_));
        ZBigStepsSet.setText(nf_.format(mediumMovementZ_));
        LRSmallStepsSet.setText(nf_.format(smallMovementLR_));
        LRLargeStepsSet.setText(nf_.format(mediumMovementLR_));

        StrVector loadedDevices = core_.getLoadedDevices();
        for (int i = 0; i < loadedDevices.size(); i++) {
            if (loadedDevices.get(i).equals("Camera")) {
                isCameraLoaded = true;
                CameraEnable(true);
            }
            if (loadedDevices.get(i).equals(SampleXYLabel)) {
                isXYStageLoaded = true;
                XYStageEnable(true);
            }
            if (loadedDevices.get(i).equals(ObjectiveXYLabel)) {
                isLRStageLoaded = true;
                LRStageEnable(true);
            }
            if (loadedDevices.get(i).equals(ObjectiveZLabel)) {
                isZStageLoaded = true;
                ZStageEnable(true);
            }
            if (loadedDevices.get(i).equals("Laser 405nm")) {
                isLaserLoaded = true;
                LaserEnable(true);
            }
            if (loadedDevices.get(i).equals("FEISEM-MT")) {
                isSEMLoaded = true;
                SEMEnable(true);
            }
        }

        try {
            core_.setXYStageDevice(SampleXYLabel);
        } catch (Exception e) {
            gui_.logError(e);
        }

        setBackground(gui_.getBackgroundColor());
        gui_.addMMBackgroundListener(this);

    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jList1 = new javax.swing.JList();
        jTabbedPane1 = new javax.swing.JTabbedPane();
        jPanel2 = new javax.swing.JPanel();
        jPanel3 = new javax.swing.JPanel();
        jPanel4 = new javax.swing.JPanel();
        XYSmallLeft = new javax.swing.JButton();
        XYSmallDown = new javax.swing.JButton();
        XYBigLeft = new javax.swing.JButton();
        XYMedLeft = new javax.swing.JButton();
        XYSmallUp = new javax.swing.JButton();
        XYMedDown = new javax.swing.JButton();
        XYBigUp = new javax.swing.JButton();
        XYSmallRight = new javax.swing.JButton();
        XYBigDown = new javax.swing.JButton();
        XYBigRight = new javax.swing.JButton();
        XYMedUp = new javax.swing.JButton();
        XYMedRight = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jTextField3 = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jTextField2 = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jTextField1 = new javax.swing.JTextField();
        jLabel18 = new javax.swing.JLabel();
        XPositionLabel = new javax.swing.JLabel();
        YPositionLabel = new javax.swing.JLabel();
        jLabel91 = new javax.swing.JLabel();
        jLabel92 = new javax.swing.JLabel();
        XPositionSet = new javax.swing.JTextField();
        YPositionSet = new javax.swing.JTextField();
        jLabel93 = new javax.swing.JLabel();
        XYMove = new javax.swing.JButton();
        jPanel5 = new javax.swing.JPanel();
        jLabel15 = new javax.swing.JLabel();
        jPanel6 = new javax.swing.JPanel();
        ZBigDown = new javax.swing.JButton();
        ZBigUp = new javax.swing.JButton();
        ZSmallDown = new javax.swing.JButton();
        ZSmallUp = new javax.swing.JButton();
        ZPositionLabel = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel16 = new javax.swing.JLabel();
        ZFineSlider = new javax.swing.JSlider();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        ZBigStepsSet = new javax.swing.JTextField();
        ZSmallStepsSet = new javax.swing.JTextField();
        ZDownSlider = new javax.swing.JSlider();
        jLabel17 = new javax.swing.JLabel();
        ZUpSlider = new javax.swing.JSlider();
        jLabel19 = new javax.swing.JLabel();
        jSeparator4 = new javax.swing.JSeparator();
        XYStageReset = new javax.swing.JButton();
        jPanel7 = new javax.swing.JPanel();
        jPanel8 = new javax.swing.JPanel();
        jPower3 = new javax.swing.JLabel();
        Laser488mWSet = new javax.swing.JTextField();
        Laser488PercentSet = new javax.swing.JTextField();
        Laser488OnOff = new javax.swing.JToggleButton();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        jLabel20 = new javax.swing.JLabel();
        jPanel12 = new javax.swing.JPanel();
        jPower12 = new javax.swing.JLabel();
        Laser642mWSet = new javax.swing.JTextField();
        Laser642PercentSet = new javax.swing.JTextField();
        Laser642OnOff = new javax.swing.JToggleButton();
        jLabel56 = new javax.swing.JLabel();
        jLabel57 = new javax.swing.JLabel();
        jLabel58 = new javax.swing.JLabel();
        jLabel59 = new javax.swing.JLabel();
        jLabel60 = new javax.swing.JLabel();
        jPanel13 = new javax.swing.JPanel();
        Laser365mWSet = new javax.swing.JTextField();
        Laser365OnOff = new javax.swing.JToggleButton();
        jLabel49 = new javax.swing.JLabel();
        jLabel50 = new javax.swing.JLabel();
        jLabel54 = new javax.swing.JLabel();
        jLabel21 = new javax.swing.JLabel();
        Laser365PercentSet = new javax.swing.JTextField();
        jPanel9 = new javax.swing.JPanel();
        jPower2 = new javax.swing.JLabel();
        Laser445mWSet = new javax.swing.JTextField();
        Laser445PercentSet = new javax.swing.JTextField();
        Laser445OnOff = new javax.swing.JToggleButton();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        jLabel22 = new javax.swing.JLabel();
        jLabel23 = new javax.swing.JLabel();
        jLabel24 = new javax.swing.JLabel();
        jPanel11 = new javax.swing.JPanel();
        Laser561mWSet = new javax.swing.JTextField();
        Laser561OnOff = new javax.swing.JToggleButton();
        jLabel51 = new javax.swing.JLabel();
        jLabel52 = new javax.swing.JLabel();
        jLabel53 = new javax.swing.JLabel();
        Laser561PercentSet = new javax.swing.JTextField();
        jLabel25 = new javax.swing.JLabel();
        jPanel10 = new javax.swing.JPanel();
        jPower1 = new javax.swing.JLabel();
        Laser405mWSet = new javax.swing.JTextField();
        Laser405PercentSet = new javax.swing.JTextField();
        Laser405OnOff = new javax.swing.JToggleButton();
        jLabel26 = new javax.swing.JLabel();
        jLabel27 = new javax.swing.JLabel();
        jLabel28 = new javax.swing.JLabel();
        jLabel29 = new javax.swing.JLabel();
        jLabel30 = new javax.swing.JLabel();
        jPanel14 = new javax.swing.JPanel();
        Laser532mWSet = new javax.swing.JTextField();
        Laser532OnOff = new javax.swing.JToggleButton();
        jLabel46 = new javax.swing.JLabel();
        jLabel47 = new javax.swing.JLabel();
        jLabel48 = new javax.swing.JLabel();
        jLabel31 = new javax.swing.JLabel();
        Laser532PercentSet = new javax.swing.JTextField();
        jPanel15 = new javax.swing.JPanel();
        jLabel32 = new javax.swing.JLabel();
        LRSmallStepsSet = new javax.swing.JTextField();
        LRLargeStepsSet = new javax.swing.JTextField();
        jLabel33 = new javax.swing.JLabel();
        jPanel16 = new javax.swing.JPanel();
        LRSmallLeft = new javax.swing.JButton();
        LRSmallDown = new javax.swing.JButton();
        LRBigLeft = new javax.swing.JButton();
        LRSmallUp = new javax.swing.JButton();
        LRBigDown = new javax.swing.JButton();
        LRSmallRight = new javax.swing.JButton();
        LRBigUp = new javax.swing.JButton();
        LRBigRight = new javax.swing.JButton();
        jLabel34 = new javax.swing.JLabel();
        CalibrateLR = new javax.swing.JButton();
        CrudeAutoAlignment = new javax.swing.JButton();
        jLabel80 = new javax.swing.JLabel();
        LRFormStageReset = new javax.swing.JButton();
        jPanel20 = new javax.swing.JPanel();
        jLabel42 = new javax.swing.JLabel();
        LCFilterConditioning = new javax.swing.JButton();
        LCstartWavelength = new javax.swing.JTextField();
        LCstopWavelength = new javax.swing.JTextField();
        LCstepSize = new javax.swing.JTextField();
        LCindex = new javax.swing.JTextField();
        LCpath = new javax.swing.JTextField();
        LCtitle = new javax.swing.JTextField();
        LCrunScan = new javax.swing.JButton();
        jLabel43 = new javax.swing.JLabel();
        jLabel44 = new javax.swing.JLabel();
        jLabel45 = new javax.swing.JLabel();
        jLabel55 = new javax.swing.JLabel();
        jLabel61 = new javax.swing.JLabel();
        jLabel62 = new javax.swing.JLabel();
        jPanel21 = new javax.swing.JPanel();
        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel35 = new javax.swing.JLabel();
        jLabel36 = new javax.swing.JLabel();
        jLabel37 = new javax.swing.JLabel();
        jLabel38 = new javax.swing.JLabel();
        jLabel39 = new javax.swing.JLabel();
        jLabel40 = new javax.swing.JLabel();
        jLabel41 = new javax.swing.JLabel();
        State561 = new javax.swing.JLabel();
        State365 = new javax.swing.JLabel();
        State405 = new javax.swing.JLabel();
        State445 = new javax.swing.JLabel();
        State488 = new javax.swing.JLabel();
        State532 = new javax.swing.JLabel();
        Power561 = new javax.swing.JLabel();
        Power365 = new javax.swing.JLabel();
        Power405 = new javax.swing.JLabel();
        Power445 = new javax.swing.JLabel();
        Power488 = new javax.swing.JLabel();
        Power532 = new javax.swing.JLabel();
        jLabel68 = new javax.swing.JLabel();
        LaserToggle = new javax.swing.JToggleButton();
        jLabel71 = new javax.swing.JLabel();
        Power642 = new javax.swing.JLabel();
        State642 = new javax.swing.JLabel();
        jLabel75 = new javax.swing.JLabel();
        jLabel76 = new javax.swing.JLabel();
        jPanel17 = new javax.swing.JPanel();
        jLabel69 = new javax.swing.JLabel();
        jLabel70 = new javax.swing.JLabel();
        jLabel74 = new javax.swing.JLabel();
        EMGain = new javax.swing.JTextField();
        ToggleShutter = new javax.swing.JToggleButton();
        jSeparator1 = new javax.swing.JSeparator();
        jPanel18 = new javax.swing.JPanel();
        jLabel78 = new javax.swing.JLabel();
        jLabel95 = new javax.swing.JLabel();
        SEMHFW = new javax.swing.JLabel();
        jPanel19 = new javax.swing.JPanel();
        jLabel81 = new javax.swing.JLabel();
        FilterLoadToggle = new javax.swing.JToggleButton();
        jLabel82 = new javax.swing.JLabel();
        LCWavelength = new javax.swing.JTextField();
        jSeparator2 = new javax.swing.JSeparator();
        jSeparator3 = new javax.swing.JSeparator();

        jList1.setModel(new javax.swing.AbstractListModel() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public Object getElementAt(int i) { return strings[i]; }
        });
        jScrollPane1.setViewportView(jList1);

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("FluoSEM Control");
        setMinimumSize(new java.awt.Dimension(1030, 670));
        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        jTabbedPane1.setName("Stage Control"); // NOI18N
        jTabbedPane1.setPreferredSize(new java.awt.Dimension(850, 797));

        XYSmallLeft.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-sl.png"))); // NOI18N
        XYSmallLeft.setBorderPainted(false);
        XYSmallLeft.setEnabled(false);
        XYSmallLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYSmallLeftActionPerformed(evt);
            }
        });

        XYSmallDown.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-sd.png"))); // NOI18N
        XYSmallDown.setBorderPainted(false);
        XYSmallDown.setEnabled(false);
        XYSmallDown.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYSmallDownActionPerformed(evt);
            }
        });

        XYBigLeft.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-tl.png"))); // NOI18N
        XYBigLeft.setBorderPainted(false);
        XYBigLeft.setEnabled(false);
        XYBigLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYBigLeftActionPerformed(evt);
            }
        });

        XYMedLeft.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-dl.png"))); // NOI18N
        XYMedLeft.setBorderPainted(false);
        XYMedLeft.setEnabled(false);
        XYMedLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYMedLeftActionPerformed(evt);
            }
        });

        XYSmallUp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-su.png"))); // NOI18N
        XYSmallUp.setBorderPainted(false);
        XYSmallUp.setEnabled(false);
        XYSmallUp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYSmallUpActionPerformed(evt);
            }
        });

        XYMedDown.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-dd.png"))); // NOI18N
        XYMedDown.setBorderPainted(false);
        XYMedDown.setEnabled(false);
        XYMedDown.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYMedDownActionPerformed(evt);
            }
        });

        XYBigUp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-tu.png"))); // NOI18N
        XYBigUp.setBorderPainted(false);
        XYBigUp.setEnabled(false);
        XYBigUp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYBigUpActionPerformed(evt);
            }
        });

        XYSmallRight.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-sr.png"))); // NOI18N
        XYSmallRight.setBorderPainted(false);
        XYSmallRight.setEnabled(false);
        XYSmallRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYSmallRightActionPerformed(evt);
            }
        });

        XYBigDown.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-td.png"))); // NOI18N
        XYBigDown.setBorderPainted(false);
        XYBigDown.setEnabled(false);
        XYBigDown.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYBigDownActionPerformed(evt);
            }
        });

        XYBigRight.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-tr.png"))); // NOI18N
        XYBigRight.setBorderPainted(false);
        XYBigRight.setEnabled(false);
        XYBigRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYBigRightActionPerformed(evt);
            }
        });

        XYMedUp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-du.png"))); // NOI18N
        XYMedUp.setBorderPainted(false);
        XYMedUp.setEnabled(false);
        XYMedUp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYMedUpActionPerformed(evt);
            }
        });

        XYMedRight.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-dr.png"))); // NOI18N
        XYMedRight.setBorderPainted(false);
        XYMedRight.setEnabled(false);
        XYMedRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYMedRightActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(XYBigLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(XYMedLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(XYBigDown, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(XYMedDown, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(XYSmallDown, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(XYBigUp, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(XYMedUp, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(XYSmallUp, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel4Layout.createSequentialGroup()
                        .addComponent(XYSmallLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(XYSmallRight, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(XYMedRight, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(XYBigRight, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel4Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(XYBigUp, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(XYMedUp, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(XYSmallUp, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(XYSmallLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(XYSmallRight, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(XYMedLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(XYBigLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(XYMedRight, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(XYBigRight, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(XYSmallDown, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(XYMedDown, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(XYBigDown, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText("XY Stage Control");

        jLabel6.setText("Large Movement (um)");

        jTextField3.setText("jTextField1");
        jTextField3.setMinimumSize(new java.awt.Dimension(69, 22));

        jLabel5.setText("Medium Movement (um)");

        jTextField2.setText("jTextField1");
        jTextField2.setMinimumSize(new java.awt.Dimension(69, 22));

        jLabel4.setText("Small Movement (um)");

        jTextField1.setText("jTextField1");
        jTextField1.setMinimumSize(new java.awt.Dimension(69, 22));

        jLabel18.setText("X:");

        XPositionLabel.setText("?");

        YPositionLabel.setText("?");

        jLabel91.setText("Y:");

        jLabel92.setText("X:");

        XPositionSet.setText("0.0");
        XPositionSet.setMinimumSize(new java.awt.Dimension(59, 20));

        YPositionSet.setText("0.0");
        YPositionSet.setMinimumSize(new java.awt.Dimension(59, 20));

        jLabel93.setText("Y:");

        XYMove.setText("Move");
        XYMove.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                XYMoveActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addComponent(jLabel6)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jTextField3, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addComponent(jLabel5)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addComponent(jLabel4)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel91)
                            .addComponent(jLabel92)
                            .addComponent(jLabel93))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(XPositionSet, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(YPositionLabel)
                            .addGroup(jPanel3Layout.createSequentialGroup()
                                .addComponent(YPositionSet, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(XYMove))))
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel3Layout.createSequentialGroup()
                                .addComponent(jLabel18)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(XPositionLabel)))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addComponent(jLabel2)
                .addGap(61, 61, 61)
                .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(37, 37, 37)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel18)
                    .addComponent(XPositionLabel))
                .addGap(3, 3, 3)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel91)
                    .addComponent(YPositionLabel))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(XPositionSet, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel92))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(YPositionSet, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(XYMove)
                    .addComponent(jLabel93))
                .addGap(18, 18, 18)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextField3, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6))
                .addContainerGap())
        );

        jLabel15.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel15.setText("Step");

        jPanel6.setPreferredSize(new java.awt.Dimension(80, 222));

        ZBigDown.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-dd.png"))); // NOI18N
        ZBigDown.setBorderPainted(false);
        ZBigDown.setEnabled(false);
        ZBigDown.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ZBigDownActionPerformed(evt);
            }
        });

        ZBigUp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-du.png"))); // NOI18N
        ZBigUp.setBorderPainted(false);
        ZBigUp.setEnabled(false);
        ZBigUp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ZBigUpActionPerformed(evt);
            }
        });

        ZSmallDown.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-sd.png"))); // NOI18N
        ZSmallDown.setBorderPainted(false);
        ZSmallDown.setEnabled(false);
        ZSmallDown.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ZSmallDownActionPerformed(evt);
            }
        });

        ZSmallUp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-su.png"))); // NOI18N
        ZSmallUp.setBorderPainted(false);
        ZSmallUp.setEnabled(false);
        ZSmallUp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ZSmallUpActionPerformed(evt);
            }
        });

        ZPositionLabel.setText("?");

        javax.swing.GroupLayout jPanel6Layout = new javax.swing.GroupLayout(jPanel6);
        jPanel6.setLayout(jPanel6Layout);
        jPanel6Layout.setHorizontalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel6Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(ZSmallUp, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ZSmallDown, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ZBigDown, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ZBigUp, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel6Layout.createSequentialGroup()
                        .addComponent(ZPositionLabel)
                        .addGap(9, 9, 9)))
                .addContainerGap())
        );
        jPanel6Layout.setVerticalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel6Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(ZBigUp, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(ZSmallUp, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(ZPositionLabel)
                .addGap(52, 52, 52)
                .addComponent(ZSmallDown, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(ZBigDown, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        ZPositionLabel.getAccessibleContext().setAccessibleName("ZPositionLabel");

        jLabel3.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel3.setText("Focus Control");

        jLabel16.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel16.setText("Fine");

        ZFineSlider.setMaximum(55);
        ZFineSlider.setMinimum(-55);
        ZFineSlider.setOrientation(javax.swing.JSlider.VERTICAL);
        ZFineSlider.setValue(0);
        ZFineSlider.setEnabled(false);
        ZFineSlider.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
            public void mouseDragged(java.awt.event.MouseEvent evt) {
                ZFineSliderMouseDragged(evt);
            }
        });

        jLabel7.setText("Small Movement Steps");

        jLabel8.setText("Large Movement Steps");

        ZBigStepsSet.setText("jTextField1");
        ZBigStepsSet.setMinimumSize(new java.awt.Dimension(69, 22));
        ZBigStepsSet.setName(""); // NOI18N

        ZSmallStepsSet.setText("jTextField1");
        ZSmallStepsSet.setMinimumSize(new java.awt.Dimension(69, 22));

        ZDownSlider.setMaximum(55);
        ZDownSlider.setValue(30);
        ZDownSlider.setEnabled(false);
        ZDownSlider.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                ZDownSliderMouseReleased(evt);
            }
        });

        jLabel17.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel17.setText("Objective Step Down Movement Size");

        ZUpSlider.setMaximum(55);
        ZUpSlider.setValue(30);
        ZUpSlider.setEnabled(false);
        ZUpSlider.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                ZUpSliderMouseReleased(evt);
            }
        });

        jLabel19.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel19.setText("Objective Step Up Movement Size");

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addGap(27, 27, 27)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jLabel15, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jPanel6, javax.swing.GroupLayout.DEFAULT_SIZE, 84, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(ZFineSlider, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel16, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(52, 52, 52))
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addComponent(jLabel8)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(ZBigStepsSet, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addGap(0, 3, Short.MAX_VALUE)
                        .addComponent(jLabel7)
                        .addGap(56, 56, 56)
                        .addComponent(ZSmallStepsSet, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel19, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ZUpSlider, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel17, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ZDownSlider, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addComponent(jLabel3)
                .addGap(26, 26, 26)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel16)
                    .addComponent(jLabel15))
                .addGap(18, 18, 18)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jPanel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(ZFineSlider, javax.swing.GroupLayout.DEFAULT_SIZE, 222, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 38, Short.MAX_VALUE)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addGap(23, 23, 23)
                        .addComponent(ZUpSlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jLabel19))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addGap(23, 23, 23)
                        .addComponent(ZDownSlider, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jLabel17))
                .addGap(45, 45, 45)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(ZSmallStepsSet, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel7))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(ZBigStepsSet, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8))
                .addContainerGap())
        );

        XYStageReset.setText("Reset ALL stages");
        XYStageReset.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                XYStageResetMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jSeparator4)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jPanel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jPanel5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 137, Short.MAX_VALUE)))
                .addContainerGap())
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(251, 251, 251)
                .addComponent(XYStageReset)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jPanel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jPanel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator4, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(XYStageReset)
                .addContainerGap(23, Short.MAX_VALUE))
        );

        jTabbedPane1.addTab("Stage Control", jPanel2);

        jPower3.setText("jPower1");

        Laser488mWSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser488mWSet.setText("0.0");
        Laser488mWSet.setAutoscrolls(false);
        Laser488mWSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser488mWSetKeyPressed(evt);
            }
        });

        Laser488PercentSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser488PercentSet.setText("0");
        Laser488PercentSet.setAutoscrolls(false);
        Laser488PercentSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser488PercentSetKeyPressed(evt);
            }
        });

        Laser488OnOff.setText("STATE: OFF");
        Laser488OnOff.setOpaque(true);
        Laser488OnOff.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Laser488OnOffActionPerformed(evt);
            }
        });

        jLabel11.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel11.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel11.setText("488 nm");

        jLabel12.setText("Set Power");

        jLabel13.setText("mW");

        jLabel14.setText("%");

        jLabel20.setText("Actual");

        jPower12.setText("jPower1");

        Laser642mWSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser642mWSet.setText("0.0");
        Laser642mWSet.setAutoscrolls(false);
        Laser642mWSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser642mWSetKeyPressed(evt);
            }
        });

        Laser642PercentSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser642PercentSet.setText("0");
        Laser642PercentSet.setAutoscrolls(false);
        Laser642PercentSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser642PercentSetKeyPressed(evt);
            }
        });

        Laser642OnOff.setText("STATE: OFF");
        Laser642OnOff.setOpaque(true);
        Laser642OnOff.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Laser642OnOffActionPerformed(evt);
            }
        });

        jLabel56.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel56.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel56.setText("642 nm");

        jLabel57.setText("Set Power");

        jLabel58.setText("mW");

        jLabel59.setText("%");

        jLabel60.setText("Actual");

        javax.swing.GroupLayout jPanel12Layout = new javax.swing.GroupLayout(jPanel12);
        jPanel12.setLayout(jPanel12Layout);
        jPanel12Layout.setHorizontalGroup(
            jPanel12Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel12Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel12Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Laser642OnOff, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel56, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel12Layout.createSequentialGroup()
                        .addGroup(jPanel12Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel57)
                            .addGroup(jPanel12Layout.createSequentialGroup()
                                .addComponent(Laser642mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel58))
                            .addGroup(jPanel12Layout.createSequentialGroup()
                                .addComponent(Laser642PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel59))
                            .addGroup(jPanel12Layout.createSequentialGroup()
                                .addComponent(jLabel60)
                                .addGap(18, 18, 18)
                                .addComponent(jPower12, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel12Layout.setVerticalGroup(
            jPanel12Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel12Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel56)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel57)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel12Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser642mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel58))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel12Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser642PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel59))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel12Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel60)
                    .addComponent(jPower12))
                .addGap(18, 18, 18)
                .addComponent(Laser642OnOff)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout jPanel8Layout = new javax.swing.GroupLayout(jPanel8);
        jPanel8.setLayout(jPanel8Layout);
        jPanel8Layout.setHorizontalGroup(
            jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel8Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Laser488OnOff, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel11, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel8Layout.createSequentialGroup()
                        .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel12)
                            .addGroup(jPanel8Layout.createSequentialGroup()
                                .addComponent(Laser488mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel13))
                            .addGroup(jPanel8Layout.createSequentialGroup()
                                .addComponent(Laser488PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel14))
                            .addGroup(jPanel8Layout.createSequentialGroup()
                                .addComponent(jLabel20)
                                .addGap(18, 18, 18)
                                .addComponent(jPower3, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
            .addComponent(jPanel12, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        jPanel8Layout.setVerticalGroup(
            jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel8Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel11)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel12)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser488mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel13))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser488PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel14))
                .addGap(18, 18, 18)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jPower3)
                    .addComponent(jLabel20))
                .addGap(18, 18, 18)
                .addComponent(Laser488OnOff)
                .addGap(18, 18, 18)
                .addComponent(jPanel12, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        Laser365mWSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser365mWSet.setText("0.0");
        Laser365mWSet.setAutoscrolls(false);
        Laser365mWSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser365mWSetKeyPressed(evt);
            }
        });

        Laser365OnOff.setText("STATE: OFF");
        Laser365OnOff.setOpaque(true);
        Laser365OnOff.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Laser365OnOffActionPerformed(evt);
            }
        });

        jLabel49.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel49.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel49.setText("365 nm");

        jLabel50.setText("Set Power");

        jLabel54.setText("mW");

        jLabel21.setText("%");

        Laser365PercentSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser365PercentSet.setText("0");
        Laser365PercentSet.setAutoscrolls(false);
        Laser365PercentSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser365PercentSetKeyPressed(evt);
            }
        });

        javax.swing.GroupLayout jPanel13Layout = new javax.swing.GroupLayout(jPanel13);
        jPanel13.setLayout(jPanel13Layout);
        jPanel13Layout.setHorizontalGroup(
            jPanel13Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel13Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel13Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel49, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel50)
                    .addGroup(jPanel13Layout.createSequentialGroup()
                        .addComponent(Laser365mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jLabel54))
                    .addGroup(jPanel13Layout.createSequentialGroup()
                        .addComponent(Laser365PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jLabel21))
                    .addComponent(Laser365OnOff, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap())
        );
        jPanel13Layout.setVerticalGroup(
            jPanel13Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel13Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel49)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel50)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel13Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser365mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel54))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel13Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser365PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel21))
                .addGap(51, 51, 51)
                .addComponent(Laser365OnOff, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jPower2.setText("jPower1");

        Laser445mWSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser445mWSet.setText("0.0");
        Laser445mWSet.setAutoscrolls(false);
        Laser445mWSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser445mWSetKeyPressed(evt);
            }
        });

        Laser445PercentSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser445PercentSet.setText("0");
        Laser445PercentSet.setAutoscrolls(false);
        Laser445PercentSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser445PercentSetKeyPressed(evt);
            }
        });

        Laser445OnOff.setText("STATE: OFF");
        Laser445OnOff.setOpaque(true);
        Laser445OnOff.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Laser445OnOffActionPerformed(evt);
            }
        });

        jLabel9.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel9.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel9.setText("445 nm");

        jLabel10.setText("Set Power");

        jLabel22.setText("mW");

        jLabel23.setText("%");

        jLabel24.setText("Actual");

        Laser561mWSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser561mWSet.setText("0.0");
        Laser561mWSet.setAutoscrolls(false);
        Laser561mWSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser561mWSetKeyPressed(evt);
            }
        });

        Laser561OnOff.setText("STATE: OFF");
        Laser561OnOff.setOpaque(true);
        Laser561OnOff.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Laser561OnOffActionPerformed(evt);
            }
        });

        jLabel51.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel51.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel51.setText("561 nm");

        jLabel52.setText("Set Power");

        jLabel53.setText("mW");

        Laser561PercentSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser561PercentSet.setText("0");
        Laser561PercentSet.setAutoscrolls(false);
        Laser561PercentSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser561PercentSetKeyPressed(evt);
            }
        });

        jLabel25.setText("%");

        javax.swing.GroupLayout jPanel11Layout = new javax.swing.GroupLayout(jPanel11);
        jPanel11.setLayout(jPanel11Layout);
        jPanel11Layout.setHorizontalGroup(
            jPanel11Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel11Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel11Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Laser561OnOff, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel51, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel11Layout.createSequentialGroup()
                        .addGroup(jPanel11Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel52)
                            .addGroup(jPanel11Layout.createSequentialGroup()
                                .addComponent(Laser561mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel53))
                            .addGroup(jPanel11Layout.createSequentialGroup()
                                .addComponent(Laser561PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel25)))
                        .addGap(0, 24, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel11Layout.setVerticalGroup(
            jPanel11Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel11Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel51)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel52)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel11Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser561mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel53))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel11Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser561PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel25))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(Laser561OnOff)
                .addContainerGap())
        );

        javax.swing.GroupLayout jPanel9Layout = new javax.swing.GroupLayout(jPanel9);
        jPanel9.setLayout(jPanel9Layout);
        jPanel9Layout.setHorizontalGroup(
            jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel9Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Laser445OnOff, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel9, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel9Layout.createSequentialGroup()
                        .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel10)
                            .addGroup(jPanel9Layout.createSequentialGroup()
                                .addComponent(Laser445mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel22))
                            .addGroup(jPanel9Layout.createSequentialGroup()
                                .addComponent(Laser445PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel23))
                            .addGroup(jPanel9Layout.createSequentialGroup()
                                .addComponent(jLabel24)
                                .addGap(18, 18, 18)
                                .addComponent(jPower2, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel9Layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(jPanel11, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        jPanel9Layout.setVerticalGroup(
            jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel9Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel9)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel10)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser445mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel22))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser445PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel23))
                .addGap(18, 18, 18)
                .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jPower2)
                    .addComponent(jLabel24))
                .addGap(18, 18, 18)
                .addComponent(Laser445OnOff)
                .addGap(18, 18, 18)
                .addComponent(jPanel11, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jPower1.setText("jPower1");

        Laser405mWSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser405mWSet.setText("0.0");
        Laser405mWSet.setAutoscrolls(false);
        Laser405mWSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser405mWSetKeyPressed(evt);
            }
        });

        Laser405PercentSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser405PercentSet.setText("0");
        Laser405PercentSet.setAutoscrolls(false);
        Laser405PercentSet.setCursor(new java.awt.Cursor(java.awt.Cursor.TEXT_CURSOR));
        Laser405PercentSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser405PercentSetKeyPressed(evt);
            }
        });

        Laser405OnOff.setText("STATE: OFF");
        Laser405OnOff.setOpaque(true);
        Laser405OnOff.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Laser405OnOffActionPerformed(evt);
            }
        });

        jLabel26.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel26.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel26.setText("405 nm");

        jLabel27.setText("Set Power");

        jLabel28.setText("mW");

        jLabel29.setText("%");

        jLabel30.setText("Actual");

        Laser532mWSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser532mWSet.setText("0.0");
        Laser532mWSet.setAutoscrolls(false);
        Laser532mWSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser532mWSetKeyPressed(evt);
            }
        });

        Laser532OnOff.setText("STATE: OFF");
        Laser532OnOff.setOpaque(true);
        Laser532OnOff.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Laser532OnOffActionPerformed(evt);
            }
        });

        jLabel46.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        jLabel46.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel46.setText("532 nm");

        jLabel47.setText("Set Power");

        jLabel48.setText("mW");

        jLabel31.setText("%");

        Laser532PercentSet.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        Laser532PercentSet.setText("0");
        Laser532PercentSet.setAutoscrolls(false);
        Laser532PercentSet.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Laser532PercentSetKeyPressed(evt);
            }
        });

        javax.swing.GroupLayout jPanel14Layout = new javax.swing.GroupLayout(jPanel14);
        jPanel14.setLayout(jPanel14Layout);
        jPanel14Layout.setHorizontalGroup(
            jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel14Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Laser532OnOff, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel46, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel14Layout.createSequentialGroup()
                        .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel47)
                            .addGroup(jPanel14Layout.createSequentialGroup()
                                .addComponent(Laser532mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel48))
                            .addGroup(jPanel14Layout.createSequentialGroup()
                                .addComponent(Laser532PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel31)))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel14Layout.setVerticalGroup(
            jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel14Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel46)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel47)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser532mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel48))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel14Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser532PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel31))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 36, Short.MAX_VALUE)
                .addComponent(Laser532OnOff)
                .addGap(21, 21, 21))
        );

        javax.swing.GroupLayout jPanel10Layout = new javax.swing.GroupLayout(jPanel10);
        jPanel10.setLayout(jPanel10Layout);
        jPanel10Layout.setHorizontalGroup(
            jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel14, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(jPanel10Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(Laser405OnOff, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel26, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel10Layout.createSequentialGroup()
                        .addGroup(jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel27)
                            .addGroup(jPanel10Layout.createSequentialGroup()
                                .addComponent(Laser405mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel28))
                            .addGroup(jPanel10Layout.createSequentialGroup()
                                .addComponent(Laser405PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jLabel29))
                            .addGroup(jPanel10Layout.createSequentialGroup()
                                .addComponent(jLabel30)
                                .addGap(18, 18, 18)
                                .addComponent(jPower1, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel10Layout.setVerticalGroup(
            jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel10Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel26)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel27)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser405mWSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel28))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(Laser405PercentSet, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel29))
                .addGap(18, 18, 18)
                .addGroup(jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jPower1)
                    .addComponent(jLabel30))
                .addGap(18, 18, 18)
                .addComponent(Laser405OnOff, javax.swing.GroupLayout.PREFERRED_SIZE, 25, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jPanel14, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(208, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout jPanel7Layout = new javax.swing.GroupLayout(jPanel7);
        jPanel7.setLayout(jPanel7Layout);
        jPanel7Layout.setHorizontalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel7Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel13, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jPanel10, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jPanel9, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jPanel8, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        jPanel7Layout.setVerticalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel7Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel10, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addComponent(jPanel9, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jPanel13, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jPanel8, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );

        jTabbedPane1.addTab("Laser Control", jPanel7);

        jLabel32.setText("Small Movement Steps");

        LRSmallStepsSet.setText("jTextField1");
        LRSmallStepsSet.setMinimumSize(new java.awt.Dimension(69, 22));

        LRLargeStepsSet.setText("jTextField1");
        LRLargeStepsSet.setMinimumSize(new java.awt.Dimension(59, 22));

        jLabel33.setText("Large Movement Steps");

        LRSmallLeft.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-sl.png"))); // NOI18N
        LRSmallLeft.setBorderPainted(false);
        LRSmallLeft.setEnabled(false);
        LRSmallLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRSmallLeftActionPerformed(evt);
            }
        });

        LRSmallDown.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-sd.png"))); // NOI18N
        LRSmallDown.setBorderPainted(false);
        LRSmallDown.setEnabled(false);
        LRSmallDown.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRSmallDownActionPerformed(evt);
            }
        });

        LRBigLeft.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-dl.png"))); // NOI18N
        LRBigLeft.setBorderPainted(false);
        LRBigLeft.setEnabled(false);
        LRBigLeft.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRBigLeftActionPerformed(evt);
            }
        });

        LRSmallUp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-su.png"))); // NOI18N
        LRSmallUp.setBorderPainted(false);
        LRSmallUp.setEnabled(false);
        LRSmallUp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRSmallUpActionPerformed(evt);
            }
        });

        LRBigDown.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-dd.png"))); // NOI18N
        LRBigDown.setBorderPainted(false);
        LRBigDown.setEnabled(false);
        LRBigDown.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRBigDownActionPerformed(evt);
            }
        });

        LRSmallRight.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-sr.png"))); // NOI18N
        LRSmallRight.setBorderPainted(false);
        LRSmallRight.setEnabled(false);
        LRSmallRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRSmallRightActionPerformed(evt);
            }
        });

        LRBigUp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-du.png"))); // NOI18N
        LRBigUp.setBorderPainted(false);
        LRBigUp.setEnabled(false);
        LRBigUp.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRBigUpActionPerformed(evt);
            }
        });

        LRBigRight.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iLEM/icons/arrowhead-dr.png"))); // NOI18N
        LRBigRight.setBorderPainted(false);
        LRBigRight.setEnabled(false);
        LRBigRight.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LRBigRightActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel16Layout = new javax.swing.GroupLayout(jPanel16);
        jPanel16.setLayout(jPanel16Layout);
        jPanel16Layout.setHorizontalGroup(
            jPanel16Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel16Layout.createSequentialGroup()
                .addContainerGap(68, Short.MAX_VALUE)
                .addGroup(jPanel16Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(LRBigDown)
                    .addGroup(jPanel16Layout.createSequentialGroup()
                        .addComponent(LRBigLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(LRSmallLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(LRSmallDown, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel16Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel16Layout.createSequentialGroup()
                        .addComponent(LRSmallUp)
                        .addContainerGap(62, Short.MAX_VALUE))
                    .addGroup(jPanel16Layout.createSequentialGroup()
                        .addGroup(jPanel16Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(LRBigUp, javax.swing.GroupLayout.PREFERRED_SIZE, 63, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel16Layout.createSequentialGroup()
                                .addComponent(LRSmallRight, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(LRBigRight, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(0, 0, Short.MAX_VALUE))))
        );
        jPanel16Layout.setVerticalGroup(
            jPanel16Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel16Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(LRBigUp, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(LRSmallUp, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel16Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(LRSmallRight, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(LRSmallLeft, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(LRBigLeft, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(LRBigRight, javax.swing.GroupLayout.PREFERRED_SIZE, 26, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(LRSmallDown, javax.swing.GroupLayout.PREFERRED_SIZE, 16, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(LRBigDown, javax.swing.GroupLayout.PREFERRED_SIZE, 24, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(46, 46, 46))
        );

        jLabel34.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel34.setText("Manual Objective Control");

        CalibrateLR.setText("Calibrate LR movement steps");
        CalibrateLR.setEnabled(false);
        CalibrateLR.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                CalibrateLRMouseClicked(evt);
            }
        });

        CrudeAutoAlignment.setText("Perform Autoalignment");
        CrudeAutoAlignment.setEnabled(false);
        CrudeAutoAlignment.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CrudeAutoAlignmentActionPerformed(evt);
            }
        });

        jLabel80.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel80.setText("Automatic Alignments / Calibration");

        LRFormStageReset.setText("Reset ALL stages");
        LRFormStageReset.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                LRFormStageResetMouseClicked(evt);
            }
        });

        javax.swing.GroupLayout jPanel15Layout = new javax.swing.GroupLayout(jPanel15);
        jPanel15.setLayout(jPanel15Layout);
        jPanel15Layout.setHorizontalGroup(
            jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel15Layout.createSequentialGroup()
                .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel15Layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(jPanel15Layout.createSequentialGroup()
                                .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel33)
                                    .addComponent(jLabel32))
                                .addGap(60, 60, 60)
                                .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(LRLargeStepsSet, javax.swing.GroupLayout.DEFAULT_SIZE, 69, Short.MAX_VALUE)
                                    .addComponent(LRSmallStepsSet, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                            .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addComponent(jPanel16, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jLabel34, javax.swing.GroupLayout.DEFAULT_SIZE, 263, Short.MAX_VALUE)))
                        .addGap(71, 71, 71)
                        .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(CalibrateLR, javax.swing.GroupLayout.DEFAULT_SIZE, 199, Short.MAX_VALUE)
                            .addComponent(CrudeAutoAlignment, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel80, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                    .addGroup(jPanel15Layout.createSequentialGroup()
                        .addGap(86, 86, 86)
                        .addComponent(LRFormStageReset)))
                .addContainerGap(118, Short.MAX_VALUE))
        );
        jPanel15Layout.setVerticalGroup(
            jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel15Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel34)
                    .addComponent(jLabel80))
                .addGap(18, 18, 18)
                .addComponent(CalibrateLR)
                .addGap(18, 18, 18)
                .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel15Layout.createSequentialGroup()
                        .addComponent(jPanel16, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(64, 64, 64)
                        .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(LRSmallStepsSet, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel32))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel15Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(LRLargeStepsSet, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel33)))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel15Layout.createSequentialGroup()
                        .addComponent(CrudeAutoAlignment)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addComponent(LRFormStageReset)
                .addGap(321, 321, 321))
        );

        jTabbedPane1.addTab("Alignments", jPanel15);

        jLabel42.setText("Condition LC Filter - Takes ~3 minutes - Needs to be done if it hasn't been used for a few days.");

        LCFilterConditioning.setText("Condition");
        LCFilterConditioning.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LCFilterConditioningActionPerformed(evt);
            }
        });

        LCstartWavelength.setText("400.0");

        LCstopWavelength.setText("720.0");

        LCstepSize.setText("50.0");

        LCindex.setText("1");

        LCpath.setText("C:\\\\LCTEST\\\\");

            LCtitle.setText("TEST1");

            LCrunScan.setText("Start");
            LCrunScan.addActionListener(new java.awt.event.ActionListener() {
                public void actionPerformed(java.awt.event.ActionEvent evt) {
                    LCrunScanActionPerformed(evt);
                }
            });

            jLabel43.setText("Start Wavelength");

            jLabel44.setText("Stop Wavelength");

            jLabel45.setText("Step Size");

            jLabel55.setText("Index");

            jLabel61.setText("Directory");

            jLabel62.setText("Title");

            javax.swing.GroupLayout jPanel20Layout = new javax.swing.GroupLayout(jPanel20);
            jPanel20.setLayout(jPanel20Layout);
            jPanel20Layout.setHorizontalGroup(
                jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel20Layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel20Layout.createSequentialGroup()
                            .addComponent(jLabel42)
                            .addGap(18, 18, 18)
                            .addComponent(LCFilterConditioning))
                        .addGroup(jPanel20Layout.createSequentialGroup()
                            .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel43)
                                .addComponent(jLabel44)
                                .addComponent(jLabel45)
                                .addComponent(jLabel55)
                                .addComponent(jLabel61)
                                .addComponent(jLabel62))
                            .addGap(56, 56, 56)
                            .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(LCrunScan)
                                .addComponent(LCindex, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(LCstepSize, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(LCtitle, javax.swing.GroupLayout.PREFERRED_SIZE, 407, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(LCpath, javax.swing.GroupLayout.PREFERRED_SIZE, 407, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(LCstopWavelength, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(LCstartWavelength, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addContainerGap(99, Short.MAX_VALUE))
            );
            jPanel20Layout.setVerticalGroup(
                jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel20Layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel42)
                        .addComponent(LCFilterConditioning))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(LCstartWavelength, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel43))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(LCstopWavelength, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel44))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(LCstepSize, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel45))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(LCindex, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel55))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(LCpath, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel61))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel20Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(LCtitle, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel62))
                    .addGap(18, 18, 18)
                    .addComponent(LCrunScan)
                    .addContainerGap(308, Short.MAX_VALUE))
            );

            jTabbedPane1.addTab("LC Filter", jPanel20);

            javax.swing.GroupLayout jPanel21Layout = new javax.swing.GroupLayout(jPanel21);
            jPanel21.setLayout(jPanel21Layout);
            jPanel21Layout.setHorizontalGroup(
                jPanel21Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGap(0, 661, Short.MAX_VALUE)
            );
            jPanel21Layout.setVerticalGroup(
                jPanel21Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGap(0, 611, Short.MAX_VALUE)
            );

            jTabbedPane1.addTab("Scripting", jPanel21);

            jLabel1.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
            jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
            jLabel1.setText("STATUS");

            jLabel35.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
            jLabel35.setText("Lasers");

            jLabel36.setText("365 nm");

            jLabel37.setText("405 nm");

            jLabel38.setText("445 nm");

            jLabel39.setText("488 nm");

            jLabel40.setText("532 nm");

            jLabel41.setText("561 nm");

            State561.setBackground(new java.awt.Color(0, 255, 0));
            State561.setText("?");
            State561.setOpaque(true);

            State365.setBackground(new java.awt.Color(0, 255, 0));
            State365.setText("?");
            State365.setOpaque(true);

            State405.setBackground(new java.awt.Color(0, 255, 0));
            State405.setText("?");
            State405.setOpaque(true);

            State445.setBackground(new java.awt.Color(0, 255, 0));
            State445.setText("?");
            State445.setOpaque(true);

            State488.setBackground(new java.awt.Color(0, 255, 0));
            State488.setText("?");
            State488.setOpaque(true);

            State532.setBackground(new java.awt.Color(0, 255, 0));
            State532.setText("?");
            State532.setOpaque(true);

            Power561.setText("?");

            Power365.setText("?");

            Power405.setText("?");

            Power445.setText("?");

            Power488.setText("?");

            Power532.setText("?");

            jLabel68.setText("Toggle enabled lasers ON/OFF");

            LaserToggle.setText("STATE: OFF");
            LaserToggle.setEnabled(false);
            LaserToggle.setOpaque(true);
            LaserToggle.addActionListener(new java.awt.event.ActionListener() {
                public void actionPerformed(java.awt.event.ActionEvent evt) {
                    LaserToggleActionPerformed(evt);
                }
            });

            jLabel71.setText("642 nm");

            Power642.setText("?");

            State642.setBackground(new java.awt.Color(0, 255, 0));
            State642.setText("?");
            State642.setOpaque(true);

            jLabel75.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
            jLabel75.setText("Power");

            jLabel76.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
            jLabel76.setText("State");

            javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
            jPanel1.setLayout(jPanel1Layout);
            jPanel1Layout.setHorizontalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel1Layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addComponent(jLabel35)
                            .addGap(0, 0, Short.MAX_VALUE))
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel68)
                                .addGroup(jPanel1Layout.createSequentialGroup()
                                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(jLabel36)
                                        .addComponent(jLabel37)
                                        .addComponent(jLabel38)
                                        .addComponent(jLabel39)
                                        .addComponent(jLabel40)
                                        .addComponent(jLabel41)
                                        .addComponent(jLabel71))
                                    .addGap(60, 60, 60)
                                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(Power365)
                                        .addComponent(Power405)
                                        .addComponent(Power445)
                                        .addComponent(Power488)
                                        .addComponent(Power532)
                                        .addComponent(Power561)
                                        .addComponent(Power642)
                                        .addComponent(jLabel75))))
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jLabel76)
                                    .addComponent(State561, javax.swing.GroupLayout.DEFAULT_SIZE, 59, Short.MAX_VALUE)
                                    .addComponent(State532, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(State488, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(State445, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(State405, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(State365, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(State642, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addComponent(LaserToggle, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 139, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addContainerGap())
            );
            jPanel1Layout.setVerticalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel1Layout.createSequentialGroup()
                    .addComponent(jLabel1)
                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel35)
                        .addComponent(jLabel75)
                        .addComponent(jLabel76))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel1Layout.createSequentialGroup()
                                .addComponent(jLabel36)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel37)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel38)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel39)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel40)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel41)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(jLabel71)
                                    .addComponent(State642)))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel1Layout.createSequentialGroup()
                                .addComponent(State365)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(State405)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(State445)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(State488)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(State532)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(State561)))
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addComponent(Power365)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(Power405)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(Power445)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(Power488)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(Power532)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(Power561)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                            .addComponent(Power642)))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel68)
                        .addComponent(LaserToggle))
                    .addContainerGap())
            );

            jLabel69.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
            jLabel69.setText("Camera");

            jLabel70.setText("EM Gain");

            jLabel74.setText("Toggle shutter OPEN/CLOSED");

            EMGain.setText("?");
            EMGain.setEnabled(false);
            EMGain.addKeyListener(new java.awt.event.KeyAdapter() {
                public void keyPressed(java.awt.event.KeyEvent evt) {
                    EMGainKeyPressed(evt);
                }
            });

            ToggleShutter.setText("STATE:CLOSED");
            ToggleShutter.setEnabled(false);
            ToggleShutter.addChangeListener(new javax.swing.event.ChangeListener() {
                public void stateChanged(javax.swing.event.ChangeEvent evt) {
                    ToggleShutterStateChanged(evt);
                }
            });

            javax.swing.GroupLayout jPanel17Layout = new javax.swing.GroupLayout(jPanel17);
            jPanel17.setLayout(jPanel17Layout);
            jPanel17Layout.setHorizontalGroup(
                jPanel17Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel17Layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanel17Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel17Layout.createSequentialGroup()
                            .addComponent(jLabel70)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(EMGain, javax.swing.GroupLayout.PREFERRED_SIZE, 61, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel17Layout.createSequentialGroup()
                            .addComponent(jLabel69)
                            .addGap(0, 0, Short.MAX_VALUE))
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel17Layout.createSequentialGroup()
                            .addComponent(jLabel74)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(ToggleShutter)))
                    .addContainerGap())
                .addComponent(jSeparator1)
            );
            jPanel17Layout.setVerticalGroup(
                jPanel17Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel17Layout.createSequentialGroup()
                    .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                    .addComponent(jLabel69)
                    .addGap(18, 18, 18)
                    .addGroup(jPanel17Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel70)
                        .addComponent(EMGain, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel17Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel74)
                        .addComponent(ToggleShutter))
                    .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            );

            jLabel78.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
            jLabel78.setText("SEM");

            jLabel95.setText("Horizontal FOV (um)");

            SEMHFW.setText("?");

            javax.swing.GroupLayout jPanel18Layout = new javax.swing.GroupLayout(jPanel18);
            jPanel18.setLayout(jPanel18Layout);
            jPanel18Layout.setHorizontalGroup(
                jPanel18Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel18Layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanel18Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel18Layout.createSequentialGroup()
                            .addComponent(jLabel95)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 86, Short.MAX_VALUE)
                            .addComponent(SEMHFW)
                            .addGap(112, 112, 112))
                        .addGroup(jPanel18Layout.createSequentialGroup()
                            .addComponent(jLabel78)
                            .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
            );
            jPanel18Layout.setVerticalGroup(
                jPanel18Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel18Layout.createSequentialGroup()
                    .addComponent(jLabel78)
                    .addGap(40, 40, 40)
                    .addGroup(jPanel18Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel95)
                        .addComponent(SEMHFW))
                    .addContainerGap(16, Short.MAX_VALUE))
            );

            jLabel81.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
            jLabel81.setText("LC Filter");

            FilterLoadToggle.setText("STATE:UNLOADED");
            FilterLoadToggle.setRolloverEnabled(false);
            FilterLoadToggle.addChangeListener(new javax.swing.event.ChangeListener() {
                public void stateChanged(javax.swing.event.ChangeEvent evt) {
                    FilterLoadToggleStateChanged(evt);
                }
            });

            jLabel82.setText("Wavelength");

            LCWavelength.setText("?");
            LCWavelength.setEnabled(false);
            LCWavelength.addKeyListener(new java.awt.event.KeyAdapter() {
                public void keyPressed(java.awt.event.KeyEvent evt) {
                    LCWavelengthKeyPressed(evt);
                }
            });

            javax.swing.GroupLayout jPanel19Layout = new javax.swing.GroupLayout(jPanel19);
            jPanel19.setLayout(jPanel19Layout);
            jPanel19Layout.setHorizontalGroup(
                jPanel19Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel19Layout.createSequentialGroup()
                    .addContainerGap()
                    .addGroup(jPanel19Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jLabel81)
                        .addComponent(jLabel82))
                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel19Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(FilterLoadToggle, javax.swing.GroupLayout.DEFAULT_SIZE, 159, Short.MAX_VALUE)
                        .addComponent(LCWavelength))
                    .addContainerGap())
            );
            jPanel19Layout.setVerticalGroup(
                jPanel19Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel19Layout.createSequentialGroup()
                    .addGroup(jPanel19Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(FilterLoadToggle)
                        .addComponent(jLabel81))
                    .addGap(18, 18, 18)
                    .addGroup(jPanel19Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel82)
                        .addComponent(LCWavelength, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            );

            javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
            getContentPane().setLayout(layout);
            layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(jTabbedPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 666, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jSeparator3)
                        .addComponent(jPanel17, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jPanel18, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jPanel19, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jSeparator2, javax.swing.GroupLayout.Alignment.TRAILING)
                        .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
            );
            layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                    .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jTabbedPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 639, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGroup(layout.createSequentialGroup()
                            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(jPanel17, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGap(26, 26, 26)
                            .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(jPanel19, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(jSeparator3, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(jPanel18, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
            );

            pack();
        }// </editor-fold>//GEN-END:initComponents

    private void setRelativeXYStagePosition(double x, double y) {
        updateMovementFields();
        try {
            positionTimer.stop();
            core_.setRelativeXYPosition(SampleXYLabel, x, y);
            positionTimer.start();
        } catch (Exception e) {
            gui_.logError(e);
        }
    }

    private void setRelativeStagePosition(double z) {
        updateMovementFields();
        try {
            positionTimer.stop();
            core_.setRelativePosition(ObjectiveZLabel, z);
            positionTimer.start();
        } catch (Exception e) {
            gui_.logError(e);
        }
        ZFineSlider.setValue(0);
    }

    private void setRelativeLRStagePosition(double x, double y) {
        updateMovementFields();
        try {
            core_.setXYStageDevice(ObjectiveXYLabel);
        } catch (Exception e) {
            gui_.logError(e);
        }
        try {
            positionTimer.stop();
            core_.setRelativeXYPosition(ObjectiveXYLabel, x, y);
            positionTimer.start();
        } catch (Exception e) {
            gui_.logError(e);
        }
        try {
            core_.setXYStageDevice(SampleXYLabel);
        } catch (Exception e) {
            gui_.logError(e);
        }
    }

    private void Laser532PercentSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser532PercentSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser532PercentSet.getText()) > 100)
                    {
                        Laser532PercentSet.setText("100");
                    }
            
            try {
                core_.setProperty(nm532PLabel, "Volts", (5.0 - Float.parseFloat(Laser532PercentSet.getText()) / 20));
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*  try {
             jLaserPercentSet3.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/
            try {
                Laser532mWSet.setText(Double.toString(Math.round((Double.parseDouble(Laser532PercentSet.getText()) * 3) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser532PercentSetKeyPressed

    private void Laser532OnOffActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Laser532OnOffActionPerformed
        if (Laser532OnOff.isSelected() && LaserToggle.isSelected()) {
            try {
                core_.setProperty(nm532Label, "Laser", "On");
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser532OnOff.setText("STATE: ON");
            State532.setText("ON");
            State532.setBackground(Color.red);
            Laser532OnOff.setBackground(Color.red);
            /* try {
             core_.setProperty(nm532ENLabel, "Volts", 5.0);
             } catch (Exception e) {
             gui_.logError(e);
             }*/
        } else if (Laser532OnOff.isSelected() && !LaserToggle.isSelected()) {
            Laser532OnOff.setText("STATE: READY");
            State532.setText("READY");
            State532.setBackground(Color.yellow);
            Laser532OnOff.setBackground(Color.yellow);
            try {
                core_.setProperty(nm532Label, "Laser", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty(nm532Label, "Laser", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser532OnOff.setText("STATE: OFF");
            State532.setText("OFF");
            State532.setBackground(Color.green);
            Laser532OnOff.setBackground(Color.green);
            /*try {
             core_.setProperty(nm532ENLabel, "Volts", 0.0);
             } catch (Exception e) {
             gui_.logError(e);
             }*/
        }
    }//GEN-LAST:event_Laser532OnOffActionPerformed

    private void Laser532mWSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser532mWSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser532mWSet.getText()) > 300)
                    {
                        Laser532mWSet.setText("300");
                    }
            try {
                core_.setProperty(nm532PLabel, "Volts", (5.0 - (Float.parseFloat(Laser532mWSet.getText()) / 60)));
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                Laser532PercentSet.setText(Double.toString(Math.round((Double.parseDouble(Laser532mWSet.getText()) / 3) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser532mWSetKeyPressed

    private void Laser405OnOffActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Laser405OnOffActionPerformed
        if (Laser405OnOff.isSelected() && LaserToggle.isSelected()) {
            try {
                core_.setProperty(nm405Label, "Laser Operation Select", "On");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm405ENLabel, "Volts", 5.0);

            } catch (Exception e) {
                gui_.logError(e);

            }
            Laser405OnOff.setText("STATE: ON");
            State405.setText("ON");
            State405.setBackground(Color.red);
            Laser405OnOff.setBackground(Color.red);
        } else if (Laser405OnOff.isSelected() && !LaserToggle.isSelected()) {
            Laser405OnOff.setText("STATE: READY");
            State405.setText("READY");
            State405.setBackground(Color.yellow);
            Laser405OnOff.setBackground(Color.yellow);
            try {
                core_.setProperty(nm405Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm405ENLabel, "Volts", "0.0");

            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty(nm405Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm405ENLabel, "Volts", "0.0");

            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser405OnOff.setText("STATE: OFF");
            State405.setText("OFF");
            State405.setBackground(Color.green);
            Laser405OnOff.setBackground(Color.green);
        }
    }//GEN-LAST:event_Laser405OnOffActionPerformed

    private void Laser405PercentSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser405PercentSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser405PercentSet.getText()) > 100)
                    {
                        Laser405PercentSet.setText("100");
                    }
            
            try {
                core_.setProperty(nm405PLabel, "Volts", Float.parseFloat(Laser405PercentSet.getText()) / 20);
            } catch (Exception e) {
                gui_.logError(e);
            }
            /* try {
             jLaserPercentSet1.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/
            try {
                Laser405mWSet.setText(Double.toString(Math.round((Double.parseDouble(Laser405PercentSet.getText()) * 1.2) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser405PercentSetKeyPressed

    private void Laser405mWSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser405mWSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser405mWSet.getText()) > 120)
                    {
                        Laser405mWSet.setText("120");
                    }
            try {
                core_.setProperty(nm405PLabel, "Volts", Float.parseFloat(Laser405mWSet.getText()) / 24);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                Laser405PercentSet.setText(Double.toString(Math.round((Double.parseDouble(Laser405mWSet.getText()) / 1.2) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*     try {
             jLasermWSet1.setText(core_.getProperty(nm405Label, "Laser Power Set-point Select [mW]"));
             } catch (Exception e) {
             gui_.logError(e);
             }*/
        }
    }//GEN-LAST:event_Laser405mWSetKeyPressed

    private void Laser561PercentSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser561PercentSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser561PercentSet.getText()) > 100)
                    {
                        Laser561PercentSet.setText("100");
                    }
            try {
                core_.setProperty(nm561PLabel, "Volts", (5.0 - Float.parseFloat(Laser561PercentSet.getText()) / 20));
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*  try {
             jLaserPercentSet3.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/
            try {
                Laser561mWSet.setText(Double.toString(Math.round((Double.parseDouble(Laser561PercentSet.getText()) * 1.5) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser561PercentSetKeyPressed

    private void Laser561OnOffActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Laser561OnOffActionPerformed
        if (Laser561OnOff.isSelected() && LaserToggle.isSelected()) {
            try {
                core_.setProperty(nm561Label, "Laser", "On");
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser561OnOff.setText("STATE: ON");
            State561.setText("ON");
            State561.setBackground(Color.red);
            Laser561OnOff.setBackground(Color.red);
            /* try {
             core_.setProperty(nm561ENLabel, "Volts", 5.0);
             } catch (Exception e) {
             gui_.logError(e);
             }*/
        } else if (Laser561OnOff.isSelected() && !LaserToggle.isSelected()) {
            Laser561OnOff.setText("STATE: READY");
            State561.setText("READY");
            State561.setBackground(Color.yellow);
            Laser561OnOff.setBackground(Color.yellow);
            try {
                core_.setProperty(nm561Label, "Laser", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty(nm561Label, "Laser", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser561OnOff.setText("STATE: OFF");
            State561.setText("OFF");
            State561.setBackground(Color.green);
            Laser561OnOff.setBackground(Color.green);
            /*try {
             core_.setProperty(nm561ENLabel, "Volts", 0.0);
             } catch (Exception e) {
             gui_.logError(e);
             }*/
        }
    }//GEN-LAST:event_Laser561OnOffActionPerformed

    private void Laser561mWSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser561mWSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser561mWSet.getText()) > 150)
                    {
                        Laser561mWSet.setText("150");
                    }
            try {
                core_.setProperty(nm561PLabel, "Volts", 5.0 - (Float.parseFloat(Laser561mWSet.getText()) / 30));
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                Laser561PercentSet.setText(Double.toString(Math.round((Double.parseDouble(Laser561mWSet.getText()) / 1.5) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser561mWSetKeyPressed

    private void Laser445OnOffActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Laser445OnOffActionPerformed
        if (Laser445OnOff.isSelected() && LaserToggle.isSelected()) {
            try {
                core_.setProperty(nm445Label, "Laser Operation Select", "On");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm445ENLabel, "Volts", 5.0);

            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser445OnOff.setText("STATE: ON");
            Laser445OnOff.setBackground(Color.red);
            State445.setText("ON");
            State445.setBackground(Color.red);
        } else if (Laser365OnOff.isSelected() && !LaserToggle.isSelected()) {
            Laser445OnOff.setText("STATE: READY");
            Laser445OnOff.setBackground(Color.yellow);
            State445.setText("READY");
            State445.setBackground(Color.yellow);
            try {
                core_.setProperty(nm445Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm445ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty(nm445Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm445ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser445OnOff.setText("STATE: OFF");
            State445.setText("OFF");
            State445.setBackground(Color.green);
            Laser445OnOff.setBackground(Color.green);
        }
    }//GEN-LAST:event_Laser445OnOffActionPerformed

    private void Laser445PercentSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser445PercentSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser445PercentSet.getText()) > 100)
                    {
                        Laser445PercentSet.setText("100");
                    }
            try {
                core_.setProperty(nm445PLabel, "Volts", Float.parseFloat(Laser445PercentSet.getText()) / 20);
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*try {
             jLaserPercentSet2.setText(core_.getProperty(nm445Label, "Laser Power Set-point Select [%]").substring(0, core_.getProperty(nm445Label, "Laser Power Set-point [%]").length() - 2));
             } catch (Exception e) {
             gui_.logError(e);
             }*/
            try {
                Laser445mWSet.setText(Float.toString(Math.round((Float.parseFloat(Laser445PercentSet.getText())) * 100) / 100.f));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser445PercentSetKeyPressed

    private void Laser445mWSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser445mWSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser445mWSet.getText()) > 100)
                    {
                        Laser445mWSet.setText("100");
                    }
            try {
                core_.setProperty(nm445PLabel, "Volts", Float.parseFloat(Laser445mWSet.getText()) / 20);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                Laser445PercentSet.setText(Float.toString(Math.round((Float.parseFloat(Laser445mWSet.getText())) * 100) / 100.f));
            } catch (Exception e) {
                gui_.logError(e);
            }
            /* try {
             jLasermWSet2.setText(core_.getProperty(nm445Label, "Laser Power Set-point Select [mW]"));
             } catch (Exception e) {
             gui_.logError(e);
             }*/
        }
    }//GEN-LAST:event_Laser445mWSetKeyPressed

    private void Laser365PercentSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser365PercentSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser365PercentSet.getText()) > 100)
                    {
                        Laser365PercentSet.setText("100");
                    }
            try {
                Laser365mWSet.setText(Double.toString(Math.round((Double.parseDouble(Laser365PercentSet.getText()) * 0.03) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
            if (Laser365OnOff.isSelected()) {
                try {
                    core_.setProperty(nm365PLabel, "Volts", Float.parseFloat(Laser365PercentSet.getText()) / 20);
                } catch (Exception e) {
                    gui_.logError(e);
                }
            }
            /*  try {
             jLaserPercentSet3.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/

        }
    }//GEN-LAST:event_Laser365PercentSetKeyPressed

    private void Laser365OnOffActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Laser365OnOffActionPerformed
        if (Laser365OnOff.isSelected() && LaserToggle.isSelected()) {
            try {

                core_.setProperty(nm365PLabel, "Volts", Float.parseFloat(Laser365PercentSet.getText()) / 20);
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser365OnOff.setText("STATE: ON");
            Laser365OnOff.setBackground(Color.red);
            State365.setText("ON");
            State365.setBackground(Color.red);
        } else if (Laser365OnOff.isSelected() && !LaserToggle.isSelected()) {
            Laser365OnOff.setText("STATE: ENABLED");
            State365.setText("READY");
            State365.setBackground(Color.yellow);
            Laser365OnOff.setBackground(Color.yellow);
            try {
                core_.setProperty(nm365PLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty(nm365PLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser365OnOff.setText("STATE: OFF");
            State365.setText("OFF");
            State365.setBackground(Color.green);
            Laser365OnOff.setBackground(Color.green);
        }
    }//GEN-LAST:event_Laser365OnOffActionPerformed

    private void Laser365mWSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser365mWSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser365mWSet.getText()) > 3)
                    {
                        Laser365mWSet.setText("3");
                    }
            try {
                Laser365PercentSet.setText(Double.toString(Math.round((Double.parseDouble(Laser365mWSet.getText()) / 0.03) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
            if (Laser365OnOff.isSelected()) {
                try {
                    core_.setProperty(nm365PLabel, "Volts", Float.parseFloat(Laser365mWSet.getText()) / (float) 28);
                } catch (Exception e) {
                    gui_.logError(e);
                }
            }
            /*  try {
             jLaserPercentSet3.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/

        }
    }//GEN-LAST:event_Laser365mWSetKeyPressed

    private void Laser642OnOffActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Laser642OnOffActionPerformed
        if (Laser642OnOff.isSelected() && LaserToggle.isSelected()) {
            try {
                core_.setProperty(nm642Label, "Laser Operation Select", "On");
            } catch (Exception e) {
                gui_.logError(e);
            }

            try {
                core_.setProperty(nm642ENLabel, "Volts", 5.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser642OnOff.setText("STATE: ON");
            Laser642OnOff.setBackground(Color.red);
            State642.setText("ON");
            State642.setBackground(Color.red);

        } else if (Laser642OnOff.isSelected() && !LaserToggle.isSelected()) {
            Laser642OnOff.setText("STATE: READY");
            Laser642OnOff.setBackground(Color.yellow);
            State642.setText("READY");
            State642.setBackground(Color.yellow);
            try {
                core_.setProperty(nm642Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm642ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty(nm642Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm642ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser642OnOff.setText("STATE: OFF");
            State642.setText("OFF");
            State642.setBackground(Color.GREEN);
            Laser642OnOff.setBackground(Color.green);
        }
    }//GEN-LAST:event_Laser642OnOffActionPerformed

    private void Laser642PercentSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser642PercentSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser642PercentSet.getText()) > 100)
                    {
                        Laser642PercentSet.setText("100");
                    }
            try {

                core_.setProperty(nm642PLabel, "Volts", Float.parseFloat(Laser642PercentSet.getText()) / 20);
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*  try {
             jLaserPercentSet3.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/
            try {
                Laser642mWSet.setText(Double.toString(Math.round((Double.parseDouble(Laser642PercentSet.getText()) * 1.4) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser642PercentSetKeyPressed

    private void Laser642mWSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser642mWSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser642mWSet.getText()) > 140)
                    {
                        Laser642mWSet.setText("140");
                    }
            try {
                core_.setProperty(nm642PLabel, "Volts", Float.parseFloat(Laser642mWSet.getText()) / 28);
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*  try {
             jLaserPercentSet3.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/
            try {
                Laser642PercentSet.setText(Double.toString(Math.round((Double.parseDouble(Laser642mWSet.getText()) / 1.4) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser642mWSetKeyPressed

    private void Laser488OnOffActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Laser488OnOffActionPerformed
        if (Laser488OnOff.isSelected() && LaserToggle.isSelected()) {
            try {
                core_.setProperty(nm488Label, "Laser Operation Select", "On");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm488ENLabel, "Volts", 5.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser488OnOff.setText("STATE: ON");
            Laser488OnOff.setBackground(Color.red);
            State488.setText("ON");
            State488.setBackground(Color.red);
        } else if (Laser488OnOff.isSelected() && !LaserToggle.isSelected()) {
            Laser488OnOff.setText("STATE: READY");
            Laser488OnOff.setBackground(Color.yellow);
            State488.setText("READY");
            State488.setBackground(Color.yellow);
            try {
                core_.setProperty(nm488Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm488ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty(nm488Label, "Laser Operation Select", "Off");
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                core_.setProperty(nm488ENLabel, "Volts", 0.0);
            } catch (Exception e) {
                gui_.logError(e);
            }
            Laser488OnOff.setText("STATE: OFF");
            Laser488OnOff.setBackground(Color.green);
            State488.setText("OFF");
            State488.setBackground(Color.green);
        }
    }//GEN-LAST:event_Laser488OnOffActionPerformed

    private void Laser488PercentSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser488PercentSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser488PercentSet.getText()) > 100)
                    {
                        Laser488PercentSet.setText("100");
                    }
            try {
                core_.setProperty(nm488PLabel, "Volts", Float.parseFloat(Laser488PercentSet.getText()) / 20);
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*  try {
             jLaserPercentSet3.setText();
             } catch (Exception e) {
             gui_.logError(e);
             }*/
            try {
                Laser488mWSet.setText(Double.toString(Math.round((Double.parseDouble(Laser488PercentSet.getText()) * 2) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
        }
    }//GEN-LAST:event_Laser488PercentSetKeyPressed

    private void Laser488mWSetKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Laser488mWSetKeyPressed
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            if(Double.parseDouble(Laser488mWSet.getText()) > 200)
                    {
                        Laser488mWSet.setText("200");
                    }
            try {
                core_.setProperty(nm488PLabel, "Volts", Float.parseFloat(Laser488mWSet.getText()) / 40);
            } catch (Exception e) {
                gui_.logError(e);
            }
            try {
                Laser488PercentSet.setText(Double.toString(Math.round((Double.parseDouble(Laser488mWSet.getText()) / 2) * 100) / 100.d));
            } catch (Exception e) {
                gui_.logError(e);
            }
            /*   try {
             jLasermWSet3.setText(Double.toString(Double.parseDouble(jLasermWSet1.getText())/2));
             } catch (Exception e) {
             gui_.logError(e);
             }*/
        }
    }//GEN-LAST:event_Laser488mWSetKeyPressed

    private void ZUpSliderMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ZUpSliderMouseReleased
        try {
            core_.setProperty(ObjectiveZLabel, "Step Voltage P", ZUpSlider.getValue());
        } catch (Exception e) {
            gui_.logError(e);
        }        // TODO add your handling code here:
    }//GEN-LAST:event_ZUpSliderMouseReleased

    private void ZDownSliderMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ZDownSliderMouseReleased
        // TODO add your handling code here:
        try {
            core_.setProperty(ObjectiveZLabel, "Step Voltage N", ZDownSlider.getValue());
        } catch (Exception e) {
            gui_.logError(e);
        }
    }//GEN-LAST:event_ZDownSliderMouseReleased

    private void ZFineSliderMouseDragged(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_ZFineSliderMouseDragged
        // TODO add your handling code here:
        try {
            positionTimer.stop();
            core_.setProperty(ObjectiveZLabel, "Fine Voltage", ZFineSlider.getValue());
            positionTimer.start();
        } catch (Exception e) {
            gui_.logError(e);
        }
    }//GEN-LAST:event_ZFineSliderMouseDragged

    private void ZSmallUpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ZSmallUpActionPerformed
        setRelativeStagePosition(smallMovementZ_);
    }//GEN-LAST:event_ZSmallUpActionPerformed

    private void ZSmallDownActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ZSmallDownActionPerformed
        setRelativeStagePosition(-smallMovementZ_);
    }//GEN-LAST:event_ZSmallDownActionPerformed

    private void ZBigUpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ZBigUpActionPerformed
        setRelativeStagePosition(mediumMovementZ_);
    }//GEN-LAST:event_ZBigUpActionPerformed

    private void ZBigDownActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ZBigDownActionPerformed
        setRelativeStagePosition(-mediumMovementZ_);
    }//GEN-LAST:event_ZBigDownActionPerformed

    private void XYMedRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYMedRightActionPerformed
        setRelativeXYStagePosition(mediumMovement_, 0.0);
    }//GEN-LAST:event_XYMedRightActionPerformed

    private void XYMedUpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYMedUpActionPerformed
        setRelativeXYStagePosition(0.0, -mediumMovement_);
    }//GEN-LAST:event_XYMedUpActionPerformed

    private void XYBigRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYBigRightActionPerformed
        setRelativeXYStagePosition(largeMovement_, 0.0);
    }//GEN-LAST:event_XYBigRightActionPerformed

    private void XYBigDownActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYBigDownActionPerformed
        setRelativeXYStagePosition(0.0, largeMovement_);
    }//GEN-LAST:event_XYBigDownActionPerformed

    private void XYSmallRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYSmallRightActionPerformed
        setRelativeXYStagePosition(smallMovement_, 0.0);
    }//GEN-LAST:event_XYSmallRightActionPerformed

    private void XYBigUpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYBigUpActionPerformed
        setRelativeXYStagePosition(0.0, -largeMovement_);
    }//GEN-LAST:event_XYBigUpActionPerformed

    private void XYMedDownActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYMedDownActionPerformed
        setRelativeXYStagePosition(0.0, mediumMovement_);
    }//GEN-LAST:event_XYMedDownActionPerformed

    private void XYSmallUpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYSmallUpActionPerformed
        setRelativeXYStagePosition(0.0, -smallMovement_);
    }//GEN-LAST:event_XYSmallUpActionPerformed

    private void XYMedLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYMedLeftActionPerformed
        setRelativeXYStagePosition(-mediumMovement_, 0.0);
    }//GEN-LAST:event_XYMedLeftActionPerformed

    private void XYBigLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYBigLeftActionPerformed
        setRelativeXYStagePosition(-largeMovement_, 0.0);
    }//GEN-LAST:event_XYBigLeftActionPerformed

    private void XYSmallDownActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYSmallDownActionPerformed
        setRelativeXYStagePosition(0.0, smallMovement_);
    }//GEN-LAST:event_XYSmallDownActionPerformed

    private void XYSmallLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYSmallLeftActionPerformed
        setRelativeXYStagePosition(-smallMovement_, 0.0);
    }//GEN-LAST:event_XYSmallLeftActionPerformed

    private void LRBigRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRBigRightActionPerformed
        setRelativeLRStagePosition(mediumMovementLR_, 0.0);
    }//GEN-LAST:event_LRBigRightActionPerformed

    private void LRBigUpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRBigUpActionPerformed
        setRelativeLRStagePosition(0.0, mediumMovementLR_);
    }//GEN-LAST:event_LRBigUpActionPerformed

    private void LRSmallRightActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRSmallRightActionPerformed
        setRelativeLRStagePosition(smallMovementLR_, 0.0);
    }//GEN-LAST:event_LRSmallRightActionPerformed

    private void LRBigDownActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRBigDownActionPerformed
        setRelativeLRStagePosition(0.0, -mediumMovementLR_);
    }//GEN-LAST:event_LRBigDownActionPerformed

    private void LRSmallUpActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRSmallUpActionPerformed
        setRelativeLRStagePosition(0.0, smallMovementLR_);
    }//GEN-LAST:event_LRSmallUpActionPerformed

    private void LRBigLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRBigLeftActionPerformed
        setRelativeLRStagePosition(-mediumMovementLR_, 0.0);
    }//GEN-LAST:event_LRBigLeftActionPerformed

    private void LRSmallDownActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRSmallDownActionPerformed
        setRelativeLRStagePosition(0.0, -smallMovementLR_);
    }//GEN-LAST:event_LRSmallDownActionPerformed

    private void LRSmallLeftActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LRSmallLeftActionPerformed
        setRelativeLRStagePosition(-smallMovementLR_, 0.0);
    }//GEN-LAST:event_LRSmallLeftActionPerformed

    private void UpdateCameraProperties() {
        try {
            EMGain.setText(core_.getProperty("Camera", "EMGain"));
        } catch (Exception e) {
            gui_.logError(e);
        }
        try {
            String shutter = core_.getProperty("Camera", "MECHANICAL SHUTTER");
            ToggleShutter.setSelected(shutter.equals("OPEN"));
        } catch (Exception e) {
            gui_.logError(e);
        }

    }

    private void SetCameraProperties() {
        try {
            core_.setProperty("Camera", "EMGain", Integer.valueOf(EMGain.getText()));
        } catch (Exception e) {
            gui_.logError(e);
        }

        if (ToggleShutter.isSelected()) {
            try {
                core_.setProperty("Camera", "MECHANICAL SHUTTER", "OPEN");
            } catch (Exception e) {
                gui_.logError(e);
            }
        } else {
            try {
                core_.setProperty("Camera", "MECHANICAL SHUTTER", "CLOSE");
            } catch (Exception e) {
                gui_.logError(e);
            }
        }

    }

    private void FilterLoadToggleStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_FilterLoadToggleStateChanged
        //Load varispec driver
        if (FilterLoadToggle.isSelected()) {
            boolean loaded = false;
            StrVector loadeddevices = core_.getLoadedDevices();
            for (int i = 0; i < loadeddevices.size(); i++) {
                String device = loadeddevices.get(i);
                if (device.equals("VariSpec")) {
                    loaded = true;
                }
            }
            if (!loaded) {
                FilterLoadToggle.setText("STATE:LOADED");
                LCWavelength.setEnabled(true);
                try {
                    core_.loadDevice("VariSpec", "VariSpecDriver", "VariSpec");
                    core_.loadDevice("COM41", "SerialManager", "COM41");
                    core_.setProperty("VariSpec", "Port", "COM41");
                    core_.setProperty("COM41", "AnswerTimeout", 500.000);
                    core_.setProperty("COM41", "BaudRate", 115200);
                    core_.setProperty("COM41", "DelayBetweenCharsMs", 0.0000);
                    core_.setProperty("COM41", "Handshaking", "Off");
                    core_.setProperty("COM41", "Parity", "None");
                    core_.setProperty("COM41", "StopBits", 1);
                    core_.setProperty("COM41", "Verbose", 1);
                    core_.initializeDevice("COM41");
                    core_.initializeDevice("VariSpec");
                    UpdateLCWavelength();
                    LCFilterEnable(true);
                } catch (Exception ex) {

                    FilterLoadToggle.setText("FAILED");
                    LCWavelength.setEnabled(false);
                    LCFilterEnable(false);
                }
            }
        } else {
            FilterLoadToggle.setText("STATE:UNLOADED");
            LCWavelength.setEnabled(false);
            StrVector loadeddevices = core_.getLoadedDevices();
            for (int i = 0; i < loadeddevices.size(); i++) {
                String device = loadeddevices.get(i);
                if (device.equals("VariSpec")) {
                    try {
                        core_.unloadDevice("VariSpec");
                        core_.unloadDevice("COM41");
                        LCFilterEnable(false);
                    } catch (Exception ex) {
                        FilterLoadToggle.setText("FAILED");
                    }
                }

            }
        }
    }//GEN-LAST:event_FilterLoadToggleStateChanged
    private void UpdateLCWavelength() {
        try {
            LCWavelength.setText(core_.getProperty("VariSpec", "Wavelength"));
        } catch (Exception e) {
            gui_.logError(e);
        }
    }

    private void SetLCWavelength() {
        if(Float.valueOf(LCWavelength.getText()) < 400)
                {
                    LCWavelength.setText("400");
                }
        if(Float.valueOf(LCWavelength.getText()) > 720)
                {
                    LCWavelength.setText("720");
                }
        try {
            core_.setProperty("VariSpec", "Wavelength", Float.valueOf(LCWavelength.getText()));
        } catch (Exception e) {
            gui_.logError(e);
        }

    }
    private void LCWavelengthKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_LCWavelengthKeyPressed
        //Set LC filter wavelength 
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            SetLCWavelength();
            UpdateLCWavelength();
        }
    }//GEN-LAST:event_LCWavelengthKeyPressed

    private void EMGainKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_EMGainKeyPressed
        //Updates EMGain
        if (evt.getKeyCode() == java.awt.event.KeyEvent.VK_ENTER) {
            SetCameraProperties();
            UpdateCameraProperties();
        }
    }//GEN-LAST:event_EMGainKeyPressed

    private void CalibrateLRMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_CalibrateLRMouseClicked
        //Calibrates the objective XY axis to move 2 pixels per movement. 
        
        positionTimer.stop();
        try {
            FileReader reader1 = new FileReader("C:\\Program Files\\Micro-Manager-1.4\\KULScripts\\CalibrateLR.bsh");
            bsh.set( "gui", gui_ );
            bsh.set( "mmc", core_ );
            bsh.eval(reader1);
        } catch (IOException ex) {
            gui_.logError(ex);
        } catch (EvalError ex) {
            gui_.logError(ex);
        }
        positionTimer.start();
    }//GEN-LAST:event_CalibrateLRMouseClicked

    private void ToggleShutterStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_ToggleShutterStateChanged
        //Toggles the shutter, get updated camera properties.
        if (ToggleShutter.isSelected()) {
            ToggleShutter.setText("STATE:OPEN");

        } else {
            ToggleShutter.setText("STATE:CLOSED");
        }
        SetCameraProperties();
        UpdateCameraProperties();
    }//GEN-LAST:event_ToggleShutterStateChanged

    private void XYStageResetMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_XYStageResetMouseClicked
        ResetStages();
    }//GEN-LAST:event_XYStageResetMouseClicked

    private void LRFormStageResetMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_LRFormStageResetMouseClicked
        ResetStages();
    }//GEN-LAST:event_LRFormStageResetMouseClicked

    private void LaserToggleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LaserToggleActionPerformed
        //Sets lasers to be enabled
        
        Laser365OnOffActionPerformed(evt);
        Laser405OnOffActionPerformed(evt);
        Laser445OnOffActionPerformed(evt);
        Laser488OnOffActionPerformed(evt);
        Laser532OnOffActionPerformed(evt);
        Laser561OnOffActionPerformed(evt);
        Laser642OnOffActionPerformed(evt);
        if (LaserToggle.isSelected()) {
            LaserToggle.setText("ENABLED");
            LaserToggle.setBackground(Color.yellow);
        } else {
            LaserToggle.setText("STATE:OFF");
            Laser365OnOff.setBackground(Color.green);
        }
    }//GEN-LAST:event_LaserToggleActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        positionTimer.stop();
        laserOnTimer.stop();
        SEMTimer.stop();
        prefs_.putInt(FRAMEXPOS, (int) getLocation().getX());
        prefs_.putInt(FRAMEYPOS, (int) getLocation().getY());
        prefs_.putDouble(SMALLMOVEMENT, smallMovement_);
        prefs_.putDouble(MEDIUMMOVEMENT, mediumMovement_);
        prefs_.putDouble(LARGEMOVEMENT, largeMovement_);
        prefs_.putDouble(SMALLMOVEMENTZ, smallMovementZ_);
        prefs_.putDouble(MEDIUMMOVEMENTZ, mediumMovementZ_);
    }//GEN-LAST:event_formWindowClosing

    private void XYMoveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_XYMoveActionPerformed
        //This function does an absolute move by using the current and desired location to calculate the difference and perform a relative move.
        
        try {

            Xpos = core_.getXPosition(SampleXYLabel);
            Ypos = core_.getYPosition(SampleXYLabel);

        } catch (Exception e) {
            gui_.logError(e);
        }
        XPositionLabel.setText(String.valueOf(Xpos));
        YPositionLabel.setText(String.valueOf(Ypos));

        setRelativeXYStagePosition((Double.parseDouble(XPositionSet.getText()) - Xpos), (Double.parseDouble(YPositionSet.getText()) - Ypos));

    }//GEN-LAST:event_XYMoveActionPerformed

    private void CrudeAutoAlignmentActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CrudeAutoAlignmentActionPerformed
        //Stop the XY stage feedback off timer (otherwise will interfere whilst the script is running).
        positionTimer.stop();
        try {
            FileReader reader1 = new FileReader("C:\\Program Files\\Micro-Manager-1.4\\KULScripts\\AutoAlign.bsh");
            bsh.set( "gui", gui_ );
            bsh.set( "mmc", core_ );
            bsh.eval(reader1);
        } catch (IOException ex) {
            gui_.logError(ex);
        } catch (EvalError ex) {
            gui_.logError(ex);
        }
        //Switch timer back on:
        positionTimer.start();

    }//GEN-LAST:event_CrudeAutoAlignmentActionPerformed

    private void LCFilterConditioningActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LCFilterConditioningActionPerformed
        LCFilterConditioning.setText("Conditioning..");
        try {
            core_.setProperty("VariSpec", "Conditioning", "true");
        } catch (Exception e) {
            gui_.logError(e);
        }
        LCFilterConditioning.setText("Conditioned");
    }//GEN-LAST:event_LCFilterConditioningActionPerformed

    private void LCrunScanActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LCrunScanActionPerformed
        //Runs a LC filter scan using the beanshell script in tutorial 8
        try{   
            //Read in the script to a filereader object.
            FileReader reader1 = new FileReader("C:\\Program Files\\Micro-Manager-1.4\\KULScripts\\LCFilterScan.bsh");
            //bsh.set allows you to set variables that can be accessed by the script. bsh.get() can be used to get variables from the script
            //Need to give the script a handle to the gui and core objects:
            bsh.set( "gui", gui_ );
            bsh.set( "mmc", core_ );
            //Here are all the variables we need to define
            bsh.set("startWavelength", Float.parseFloat(LCstartWavelength.getText()));
            bsh.set("stopWavelength", Float.parseFloat(LCstopWavelength.getText()));
            bsh.set("stepSize",Float.parseFloat(LCstepSize.getText()));
            bsh.set("index", Integer.parseInt(LCindex.getText()));
            bsh.set("path", LCpath.getText());
            bsh.set("title",LCtitle.getText());
            //Run the script
            bsh.eval(reader1);
            //Update the index so you do not have to rename everytime.
            LCindex.setText(Integer.toString((Integer.parseInt(LCindex.getText()) + 1)));
        }
        catch (IOException ex)
        {
            gui_.logError(ex);
        }
        catch (EvalError ex) {
            gui_.logError(ex);
        }
    }//GEN-LAST:event_LCrunScanActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton CalibrateLR;
    private javax.swing.JButton CrudeAutoAlignment;
    private javax.swing.JTextField EMGain;
    private javax.swing.JToggleButton FilterLoadToggle;
    private javax.swing.JButton LCFilterConditioning;
    private javax.swing.JTextField LCWavelength;
    private javax.swing.JTextField LCindex;
    private javax.swing.JTextField LCpath;
    private javax.swing.JButton LCrunScan;
    private javax.swing.JTextField LCstartWavelength;
    private javax.swing.JTextField LCstepSize;
    private javax.swing.JTextField LCstopWavelength;
    private javax.swing.JTextField LCtitle;
    private javax.swing.JButton LRBigDown;
    private javax.swing.JButton LRBigLeft;
    private javax.swing.JButton LRBigRight;
    private javax.swing.JButton LRBigUp;
    private javax.swing.JButton LRFormStageReset;
    private javax.swing.JTextField LRLargeStepsSet;
    private javax.swing.JButton LRSmallDown;
    private javax.swing.JButton LRSmallLeft;
    private javax.swing.JButton LRSmallRight;
    private javax.swing.JTextField LRSmallStepsSet;
    private javax.swing.JButton LRSmallUp;
    private javax.swing.JToggleButton Laser365OnOff;
    private javax.swing.JTextField Laser365PercentSet;
    private javax.swing.JTextField Laser365mWSet;
    private javax.swing.JToggleButton Laser405OnOff;
    private javax.swing.JTextField Laser405PercentSet;
    private javax.swing.JTextField Laser405mWSet;
    private javax.swing.JToggleButton Laser445OnOff;
    private javax.swing.JTextField Laser445PercentSet;
    private javax.swing.JTextField Laser445mWSet;
    private javax.swing.JToggleButton Laser488OnOff;
    private javax.swing.JTextField Laser488PercentSet;
    private javax.swing.JTextField Laser488mWSet;
    private javax.swing.JToggleButton Laser532OnOff;
    private javax.swing.JTextField Laser532PercentSet;
    private javax.swing.JTextField Laser532mWSet;
    private javax.swing.JToggleButton Laser561OnOff;
    private javax.swing.JTextField Laser561PercentSet;
    private javax.swing.JTextField Laser561mWSet;
    private javax.swing.JToggleButton Laser642OnOff;
    private javax.swing.JTextField Laser642PercentSet;
    private javax.swing.JTextField Laser642mWSet;
    private javax.swing.JToggleButton LaserToggle;
    private javax.swing.JLabel Power365;
    private javax.swing.JLabel Power405;
    private javax.swing.JLabel Power445;
    private javax.swing.JLabel Power488;
    private javax.swing.JLabel Power532;
    private javax.swing.JLabel Power561;
    private javax.swing.JLabel Power642;
    private javax.swing.JLabel SEMHFW;
    private javax.swing.JLabel State365;
    private javax.swing.JLabel State405;
    private javax.swing.JLabel State445;
    private javax.swing.JLabel State488;
    private javax.swing.JLabel State532;
    private javax.swing.JLabel State561;
    private javax.swing.JLabel State642;
    private javax.swing.JToggleButton ToggleShutter;
    private javax.swing.JLabel XPositionLabel;
    private javax.swing.JTextField XPositionSet;
    private javax.swing.JButton XYBigDown;
    private javax.swing.JButton XYBigLeft;
    private javax.swing.JButton XYBigRight;
    private javax.swing.JButton XYBigUp;
    private javax.swing.JButton XYMedDown;
    private javax.swing.JButton XYMedLeft;
    private javax.swing.JButton XYMedRight;
    private javax.swing.JButton XYMedUp;
    private javax.swing.JButton XYMove;
    private javax.swing.JButton XYSmallDown;
    private javax.swing.JButton XYSmallLeft;
    private javax.swing.JButton XYSmallRight;
    private javax.swing.JButton XYSmallUp;
    private javax.swing.JButton XYStageReset;
    private javax.swing.JLabel YPositionLabel;
    private javax.swing.JTextField YPositionSet;
    private javax.swing.JButton ZBigDown;
    private javax.swing.JTextField ZBigStepsSet;
    private javax.swing.JButton ZBigUp;
    private javax.swing.JSlider ZDownSlider;
    private javax.swing.JSlider ZFineSlider;
    private javax.swing.JLabel ZPositionLabel;
    private javax.swing.JButton ZSmallDown;
    private javax.swing.JTextField ZSmallStepsSet;
    private javax.swing.JButton ZSmallUp;
    private javax.swing.JSlider ZUpSlider;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel18;
    private javax.swing.JLabel jLabel19;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel20;
    private javax.swing.JLabel jLabel21;
    private javax.swing.JLabel jLabel22;
    private javax.swing.JLabel jLabel23;
    private javax.swing.JLabel jLabel24;
    private javax.swing.JLabel jLabel25;
    private javax.swing.JLabel jLabel26;
    private javax.swing.JLabel jLabel27;
    private javax.swing.JLabel jLabel28;
    private javax.swing.JLabel jLabel29;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel30;
    private javax.swing.JLabel jLabel31;
    private javax.swing.JLabel jLabel32;
    private javax.swing.JLabel jLabel33;
    private javax.swing.JLabel jLabel34;
    private javax.swing.JLabel jLabel35;
    private javax.swing.JLabel jLabel36;
    private javax.swing.JLabel jLabel37;
    private javax.swing.JLabel jLabel38;
    private javax.swing.JLabel jLabel39;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel40;
    private javax.swing.JLabel jLabel41;
    private javax.swing.JLabel jLabel42;
    private javax.swing.JLabel jLabel43;
    private javax.swing.JLabel jLabel44;
    private javax.swing.JLabel jLabel45;
    private javax.swing.JLabel jLabel46;
    private javax.swing.JLabel jLabel47;
    private javax.swing.JLabel jLabel48;
    private javax.swing.JLabel jLabel49;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel50;
    private javax.swing.JLabel jLabel51;
    private javax.swing.JLabel jLabel52;
    private javax.swing.JLabel jLabel53;
    private javax.swing.JLabel jLabel54;
    private javax.swing.JLabel jLabel55;
    private javax.swing.JLabel jLabel56;
    private javax.swing.JLabel jLabel57;
    private javax.swing.JLabel jLabel58;
    private javax.swing.JLabel jLabel59;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel60;
    private javax.swing.JLabel jLabel61;
    private javax.swing.JLabel jLabel62;
    private javax.swing.JLabel jLabel68;
    private javax.swing.JLabel jLabel69;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel70;
    private javax.swing.JLabel jLabel71;
    private javax.swing.JLabel jLabel74;
    private javax.swing.JLabel jLabel75;
    private javax.swing.JLabel jLabel76;
    private javax.swing.JLabel jLabel78;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel80;
    private javax.swing.JLabel jLabel81;
    private javax.swing.JLabel jLabel82;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JLabel jLabel91;
    private javax.swing.JLabel jLabel92;
    private javax.swing.JLabel jLabel93;
    private javax.swing.JLabel jLabel95;
    private javax.swing.JList jList1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel10;
    private javax.swing.JPanel jPanel11;
    private javax.swing.JPanel jPanel12;
    private javax.swing.JPanel jPanel13;
    private javax.swing.JPanel jPanel14;
    private javax.swing.JPanel jPanel15;
    private javax.swing.JPanel jPanel16;
    private javax.swing.JPanel jPanel17;
    private javax.swing.JPanel jPanel18;
    private javax.swing.JPanel jPanel19;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel20;
    private javax.swing.JPanel jPanel21;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanel7;
    private javax.swing.JPanel jPanel8;
    private javax.swing.JPanel jPanel9;
    private javax.swing.JLabel jPower1;
    private javax.swing.JLabel jPower12;
    private javax.swing.JLabel jPower2;
    private javax.swing.JLabel jPower3;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSeparator jSeparator2;
    private javax.swing.JSeparator jSeparator3;
    private javax.swing.JSeparator jSeparator4;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JTextField jTextField3;
    // End of variables declaration//GEN-END:variables
}
