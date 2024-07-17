package org.xtuml.bp.welcome.cheatsheets.library;
import org.eclipse.jface.action.Action;
import org.eclipse.ui.cheatsheets.ICheatSheetAction;
import org.eclipse.ui.cheatsheets.ICheatSheetManager;
import org.xtuml.bp.core.ActionHome_c;
import org.xtuml.bp.core.Action_c;
import org.xtuml.bp.core.Bridge_c;
import org.xtuml.bp.core.Function_c;
import org.xtuml.bp.core.MooreActionHome_c;
import org.xtuml.bp.core.Operation_c;
import org.xtuml.bp.core.ProvidedOperation_c;
import org.xtuml.bp.core.RequiredOperation_c;
import org.xtuml.bp.core.StateMachineState_c;
import org.xtuml.bp.core.common.NonRootModelElement;
import org.xtuml.bp.utilities.ui.CanvasUtilities;
import org.xtuml.bp.welcome.cheatsheets.utilities.CheatSheetsUtilities;

public class WriteOAL extends Action implements ICheatSheetAction {

	@Override
	public void run(String[] params, ICheatSheetManager manager) {
		
		if ( params == null ){
			return;
		}
		String projectName = params[0];
		String activityType = params[1];
		String activityName = params[2];
		String OalCode = params[3];
		/* 
		 * indirect parent is one more level up parent, for interface operation it is  
		 * Component, for state machine/event it is Model Class
		 * */ 
		String indirectParent = params[4];
		String directParent = params[5];
		String containerPkg = params[6];
		
		NonRootModelElement element = CheatSheetsUtilities.findElement(projectName,containerPkg, activityType, activityName, indirectParent, directParent);
		if (element == null){
			CheatSheetsUtilities.canNotFindElementReport(activityType, activityName);
		}
		if ( element instanceof Function_c){
			((Function_c)element).setAction_semantics_internal(OalCode);
		}else if (element instanceof StateMachineState_c){
			Action_c action = Action_c.getOneSM_ACTOnR514(
	                ActionHome_c.getOneSM_AHOnR513(
			      MooreActionHome_c.getOneSM_MOAHOnR511((StateMachineState_c)element)));
			action.setAction_semantics_internal(OalCode);
			
		}else if (element instanceof RequiredOperation_c){
			((RequiredOperation_c)element).setAction_semantics_internal(OalCode);
		}else if (element instanceof ProvidedOperation_c){
			((ProvidedOperation_c)element).setAction_semantics_internal(OalCode);
		}else if (element instanceof Bridge_c){
			((Bridge_c)element).setAction_semantics_internal(OalCode);
		}else if (element instanceof Operation_c){
			((Operation_c)element).setAction_semantics_internal(OalCode);
		}
		CanvasUtilities.openActivityEditor(element);


	}



}
